/*
���ߣ�sqrtsqrxlxl,xlswmn 
�ο���csdn�е���ƪ�̳� ����һ����루bushi
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
POINT position;
bool a1;
int regcps,tmp,tmp2,tmp1;
RECT lock;

void klick(int cps,int maxn,int minn){ //ƽ��ģʽ/Ƶ��ͳһ 
	printf("\n����F6��ʼ/ֹͣ����\n����F7�����������\n����1�޸ĵ��ε㰴ʱ��\n����2�л�ģʽ\n����3�˳�����\n");
	for(;1;){
		if(GetAsyncKeyState(0x31)&0x8000){
			printf("\n�ȴ���������뵥�ε㰴ʱ����������������Χ���ֶ�ֵ0.001s��һ������1��100000֮�ڵ�������\n");
			Sleep(2000);
			cin>>tmp1>>tmp2;
			if(tmp1>tmp2) swap(tmp1,tmp2);
			printf("\nĿǰ���ε㰴ʱ�䣺");
			cout<<tmp1<<"���뵽"<<tmp2<<"����"<<endl; 
			printf("\n����F6��ʼ/ֹͣ����\n����F7�����������\n����1�޸ĵ��ε㰴ʱ��\n����2�л�ģʽ\n����3�˳�����\n");
		}
		if(GetAsyncKeyState(0x32)&0x8000){
			if(maxn==0&&minn==0){
				printf("\n��ǰΪƽ��ģʽ��ת��Ϊ������\n");
				printf("\n�ֱ���������������СƵ�ʺ����Ƶ�ʣ��ֶ�ֵ0.001s����������������1��10000֮�ڵ�������\n");
				bool flag1=0;
				int mincps,maxcps;
				while(1){
					if(flag1) break;
					cin>>mincps>>maxcps;
					if(mincps>maxcps) swap(mincps,maxcps);
					if(maxcps>10000){
						printf("\n������Χ������������\n");
						Sleep(1000);
					}
					else flag1=1; 		
				}
				minn=mincps,maxn=maxcps,cps=0;
				printf("\n����F6��ʼ/ֹͣ����\n����F7�����������\n����1�޸ĵ��ε㰴ʱ��\n����2�л�ģʽ\n����3�˳�����\n");
			}
			else{
				printf("\n��ǰΪ������ģʽ��ת��Ϊƽ��\n");
				minn=0,maxn=0;
				printf("\n������ƽ�������ֶ�ֵ0.001s����������������1��10000֮�ڵ�������\n");
				int tem;
				bool flag2=0;
				while(1){
					if(flag2) break;
					cin>>tem;
					if(tem>10000){
						printf("\n������Χ������������\n");
						Sleep(1000);
					}
					else flag2=1; 		
				}
				cps=tem;
				printf("\n����F6��ʼ/ֹͣ����\n����F7�����������\n����1�޸ĵ��ε㰴ʱ��\n����2�л�ģʽ\n����3�˳�����\n");
			}
			Sleep(1000);	
		}
		if(GetAsyncKeyState(VK_F7)&0x8000){
   			GetCursorPos(&position);
   			lock.left=lock.right=position.x;
   			lock.top=lock.bottom=position.y;
   			Sleep(1000);
   			printf("\n������ϣ�\n");
   			for(;1;){
    			ClipCursor(&lock);
    			if(GetAsyncKeyState(VK_F6)&0x8000){
					printf("\n�벻Ҫ�رմ��ڣ��������С����������F6���������㡣���㽫��1���ʼ��\n");
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
					printf("\n���������\n");
					Sleep(1000); 
				}
   				if(GetAsyncKeyState(VK_F7)&0x8000){
    				ClipCursor(NULL);
     				printf("\n������ϣ�\n");
    				Sleep(1000);
     				break;
    			}
   			}  
  		}
		if(GetAsyncKeyState(VK_F6)&0x8000){
			printf("\n�벻Ҫ�رմ��ڣ��������С����������F6���������㡣���㽫��1���ʼ��\n");
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
			printf("\n���������\n");
			Sleep(1000);
		}	
		if(GetAsyncKeyState(VK_ESCAPE)&0x8000) printf("\n����ô֪����ԭ������ô���ġ���\n");
		if(GetAsyncKeyState(0x33)&0x8000){
			printf("\n��л����ʹ�ã�\n");
			Sleep(1000);
			break;
		}
	}
}

int main(){
	srand(time(0));
	printf("��������� by sqrtsqrxlxl,xlswmn\n�Ƿ�ʹ�÷����ű�ģʽ�������������������y/n��\nע�������ģʽ���ܽ�Ϊ���٣���Ϊ��̫���˲������Ż�\n");
	string q1;
	cin>>q1;
	a1=(q1=="y"||q1=="Y")?1:0;
	if(a1){
		printf("\n�ֱ���������������СƵ�ʺ����Ƶ�ʣ��ֶ�ֵ0.001s����������������1��10000֮�ڵ�������\n");
		int mincps,maxcps;
		bool flag=0;
		while(1){
			if(flag) break;
			cin>>mincps>>maxcps;
			if(mincps>maxcps) swap(mincps,maxcps); //�����뷴���Զ�У׼ 
			if(mincps==maxcps) {
				printf("\n��⵽����������һ������ֵ���Զ�ת��Ϊƽ��ģʽ"); //ƽ��ģʽת�� 
				regcps=mincps; klick(regcps,0,0);
			}
			if(maxcps>10000){
				printf("\n������Χ������������\n");
				Sleep(1000);
			}
			else flag=1; 		
		}
		klick(0,maxcps,mincps);		
	}
	if(!a1){
		printf("\n������Ƶ�ʣ��ֶ�ֵ0.001s��һ������1��100000֮�ڵ�������\n");
		cin>>regcps;
		klick(regcps,0,0);
	} 
	return 0;
}
