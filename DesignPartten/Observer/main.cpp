#include <iostream>
#include "observer.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    //֪ͨ��  
    Subject* huhansan=new Boss();  
  
    //4���۲���ʵ��  
    Observer* tongshi1=new StockObserver("κ���",huhansan);  
    Observer* tongshi2=new StockObserver("�׹ܲ�",huhansan);  
    Observer* tongshi3=new NBAObserver("������",huhansan);  
    Observer* tongshi4=new NBAObserver("�����",huhansan);  
  
    //��4���۲��߶����뵽֪ͨ�ߵ�֪ͨ������  
    huhansan->Attach(tongshi1);  
    huhansan->Attach(tongshi2);  
    huhansan->Attach(tongshi3);  
    huhansan->Attach(tongshi4);  
      
    //κ���û�б��ϰ�֪ͨ������ȥ��  
    huhansan->Detach(tongshi1);  
  
    huhansan->SetSubjectState("�Һ����������ˣ�");  
  
    //֪ͨ  
    huhansan->Notify();  
  
    delete huhansan;  
    delete tongshi1;  
    delete tongshi2;  
    delete tongshi3;  
    delete tongshi4;  
  
    std::cout<<""<<std::endl;  
    system("pause");  
}
