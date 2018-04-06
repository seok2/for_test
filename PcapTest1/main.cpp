#include <sys/time.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <pcap/pcap.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netinet/in.h>


struct ip *iph;
struct tcphdr *tcph;

void callback(u_char *useless, const struct pcap_pkthdr *pkthdr,
                const u_char *packet)
{
    static int count = 1;
    struct ether_header *ep;
    unsigned short ether_type;
    int chcnt =0;
    int length=pkthdr->len;

    // 이더넷 헤더를 가져온다.
    ep = (struct ether_header *)packet;

    // IP 헤더를 가져오기 위해서
    // 이더넷 헤더 크기만큼 offset 한다.
    packet += sizeof(struct ether_header);

    // 프로토콜 타입을 알아낸다.
    ether_type = ntohs(ep->ether_type);

    // 만약 IP 패킷이라면
    if (ether_type == ETHERTYPE_IP)
    {
        // IP 헤더에서 데이타 정보를 출력한다.
        iph = (struct ip *)packet;
        printf("IP 패킷\n");
        printf("Version     : %d\n", iph->ip_v);
        printf("Header Len  : %d\n", iph->ip_hl);
        printf("Ident       : %d\n", ntohs(iph->ip_id));
        printf("TTL         : %d\n", iph->ip_ttl);
        printf("Src Address : %s\n", inet_ntoa(iph->ip_src));
        printf("Dst Address : %s\n", inet_ntoa(iph->ip_dst));


    printf("\n\n");
    }
}
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
    struct in_addr net_addr, mask_addr;
    const u_char *packet;
    pcap_t *pcd;


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



    dev = argv[2]; // 패킷을 캡쳐할 적당한 네트워크 디바이스 이름을 얻어온다


    // 에러가 발생했을경우
    if(dev == NULL)
    {
        printf("%s\n",errbuf);
        exit(1);
    }

    // 네트워크 디바이스 이름 출력
    printf("DEV: %s\n", dev);

    //네트워크 디바이스의 네트워크 주소와 netmask 정보를 가져오기 위해 사용
    // mask, ip 정보 얻어오기
    ret = pcap_lookupnet(dev, &netp, &maskp, errbuf);

    if(ret == -1) // 에러 발생시
    {
        printf("%s\n",errbuf);
        exit(1);
    }


    // 네트웍 어드레스를 점박이 3형제 스타일로 ??
    addr.s_addr = netp;
    net = inet_ntoa(addr);

    if(net == NULL)
    {
        perror("inet_ntoa");
        exit(1);
    }

    printf("NET: %s\n",net);


    // 마찬가지로 mask 어드레스를 점박이 3형제 스타일로
    addr.s_addr = maskp;
    mask = inet_ntoa(addr);

    if(mask == NULL)
    {
        perror("inet_ntoa");
        exit(1);
    }
    printf("MASK: %s\n",mask);
    printf("=======================\n");

    pcd = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
        if (pcd == NULL)
        {
            printf("%s\n", errbuf);
            exit(1);
        }



    pcap_loop(pcd, atoi(argv[1]), callback, NULL);
}
