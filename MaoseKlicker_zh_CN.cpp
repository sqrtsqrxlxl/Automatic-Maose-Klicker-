/*
作者：sqrtsqrxlxl,xlswmn 
参考了csdn中的两篇教程 抄了一点代码（bushi
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
POINT position;
bool a1;
int regcps,tmp,tmp2,tmp1;
RECT lock;

void klick(int cps,int maxn,int minn){ //平点模式/频率统一 
	printf("\n按下F6开始/停止连点\n按下F7锁定鼠标连点\n按下1修改单次点按时间\n按下2切换模式\n按下3退出程序\n");
	for(;1;){
		if(GetAsyncKeyState(0x31)&0x8000){
			printf("\n等待两秒后输入单次点按时长（两个整数代表范围，分度值0.001s，一个介于1和100000之内的整数）\n");
			Sleep(2000);
			cin>>tmp1>>tmp2;
			if(tmp1>tmp2) swap(tmp1,tmp2);
			printf("\n目前单次点按时间：");
			cout<<tmp1<<"毫秒到"<<tmp2<<"毫秒"<<endl; 
			printf("\n按下F6开始/停止连点\n按下F7锁定鼠标连点\n按下1修改单次点按时间\n按下2切换模式\n按下3退出程序\n");
		}
		if(GetAsyncKeyState(0x32)&0x8000){
			if(maxn==0&&minn==0){
				printf("\n当前为平点模式，转化为随机间隔\n");
				printf("\n分别输入随机化点击最小频率和最大频率（分度值0.001s，输入两个个介于1和10000之内的整数）\n");
				bool flag1=0;
				int mincps,maxcps;
				while(1){
					if(flag1) break;
					cin>>mincps>>maxcps;
					if(mincps>maxcps) swap(mincps,maxcps);
					if(maxcps>10000){
						printf("\n超出范围，请重新输入\n");
						Sleep(1000);
					}
					else flag1=1; 		
				}
				minn=mincps,maxn=maxcps,cps=0;
				printf("\n按下F6开始/停止连点\n按下F7锁定鼠标连点\n按下1修改单次点按时间\n按下2切换模式\n按下3退出程序\n");
			}
			else{
				printf("\n当前为随机间隔模式，转化为平点\n");
				minn=0,maxn=0;
				printf("\n请输入平点间隔（分度值0.001s，输入两个个介于1和10000之内的整数）\n");
				int tem;
				bool flag2=0;
				while(1){
					if(flag2) break;
					cin>>tem;
					if(tem>10000){
						printf("\n超出范围，请重新输入\n");
						Sleep(1000);
					}
					else flag2=1; 		
				}
				cps=tem;
				printf("\n按下F6开始/停止连点\n按下F7锁定鼠标连点\n按下1修改单次点按时间\n按下2切换模式\n按下3退出程序\n");
			}
			Sleep(1000);	
		}
		if(GetAsyncKeyState(VK_F7)&0x8000){
   			GetCursorPos(&position);
   			lock.left=lock.right=position.x;
   			lock.top=lock.bottom=position.y;
   			Sleep(1000);
   			printf("\n锁定完毕！\n");
   			for(;1;){
    			ClipCursor(&lock);
    			if(GetAsyncKeyState(VK_F6)&0x8000){
					printf("\n请不要关闭窗口（你可以最小化），按下F6键结束连点。连点将在1秒后开始。\n");
					Sleep(1000); 
					while(!(GetAsyncKeyState(VK_F6))){
						mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
						int LastingClickTime=0;
						if(tmp1!=0&&tmp2!=0) {
							LastingClickTime=(int)(rand()%(tmp2)+tmp1+1);
							Sleep(LastingClickTime);
						}
						mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
						if(maxn!=0&&minn!=0) cps=(int)(rand()%(maxn)+minn+1);
						Sleep(cps);
					}
					printf("\n连点结束！\n");
					Sleep(1000); 
				}
   				if(GetAsyncKeyState(VK_F7)&0x8000){
    				ClipCursor(NULL);
     				printf("\n解锁完毕！\n");
    				Sleep(1000);
     				break;
    			}
   			}  
  		}
		if(GetAsyncKeyState(VK_F6)&0x8000){
			printf("\n请不要关闭窗口（你可以最小化），按下F6键结束连点。连点将在1秒后开始。\n");
			Sleep(1000); 
			while(!(GetAsyncKeyState(VK_F6))){
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				int LastingClickTime=0;
				if(tmp1!=0&&tmp2!=0) {
					LastingClickTime=(int)(rand()%(tmp2)+tmp1+1);
					Sleep(LastingClickTime);
				}
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				if(maxn!=0&&minn!=0) cps=(int)(rand()%(maxn)+minn+1);
				Sleep(cps);
			}
			printf("\n连点结束！\n");
			Sleep(1000);
		}	
		if(GetAsyncKeyState(VK_ESCAPE)&0x8000) printf("\n你怎么知道我原来是这么做的……\n");
		if(GetAsyncKeyState(0x33)&0x8000){
			printf("\n感谢您的使用！\n");
			Sleep(1000);
			break;
		}
	}
}

int main(){
	srand(time(0));
	printf("鼠标连点器 by sqrtsqrxlxl,xlswmn\n是否使用反反脚本模式（即随机化点击间隔）（y/n）\n注：随机化模式可能较为卡顿，因为我太菜了不会做优化\n");
	string q1;
	cin>>q1;
	a1=(q1=="y"||q1=="Y")?1:0;
	if(a1){
		printf("\n分别输入随机化点击最小频率和最大频率（分度值0.001s，输入两个个介于1和10000之内的整数）\n");
		int mincps,maxcps;
		bool flag=0;
		while(1){
			if(flag) break;
			cin>>mincps>>maxcps;
			if(mincps>maxcps) swap(mincps,maxcps); //若输入反了自动校准 
			if(mincps==maxcps) {
				printf("\n检测到输入了两个一样的数值，自动转化为平点模式"); //平点模式转化 
				regcps=mincps; klick(regcps,0,0);
			}
			if(maxcps>10000){
				printf("\n超出范围，请重新输入\n");
				Sleep(1000);
			}
			else flag=1; 		
		}
		klick(0,maxcps,mincps);		
	}
	if(!a1){
		printf("\n输入点击频率（分度值0.001s，一个介于1和100000之内的整数）\n");
		cin>>regcps;
		klick(regcps,0,0);
	} 
	return 0;
}
