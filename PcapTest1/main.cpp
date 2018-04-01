#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>     //libpcap 헤더 포험
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

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

    dev = pcap_lookupdev(errbuf); // 패킷을 캡쳐할 적당한 네트워크 디바이스 이름을 얻어온다

    // 에러가 발생했을경우
    if(dev == NULL)
    {
        printf("%s\n",errbuf);
        exit(1);
    }

    // 네트워크 디바이스 이름 출력
    printf("DEV: %s\n",dev);

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
    return 0;
}
