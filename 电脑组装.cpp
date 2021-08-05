#include<iostream>
using namespace std;

//����ͬ�����
//����CPU��

class CPU{
public:
	//������㺯��
	virtual void  calculate() = 0;

};

//�����Կ���
class VideoCard {
public:
	virtual void display () = 0;
};

//�����ڴ���
class Memory{
public:
	virtual void storage() = 0;
};

//������
class Computer{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work() {
		//������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//�ṩ��������  �ͷ��������Ե����
	~Computer() {
		//�ͷ�CPU���
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete 	m_vc;
			m_vc = NULL;
		}
		if (m_vc != NULL) {
			delete 	m_vc;
			m_vc = NULL;
		}
	}
private:
	CPU* m_cpu;//cpu �����ָ��
	VideoCard* m_vc;//�Կ����ָ��
	Memory* m_mem;//�ڴ������ָ��
};


//����ĳ���
//Intel
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Inter��cpu��ʼ������" << endl;
	}
};

class IntelVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Intel���Կ���ʼ������" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel���ڴ�����ʼ������" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << " Lenovo��cpu��ʼ������" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Lenovo���Կ���ʼ������" << endl;
	}
};
class  LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << " Lenovo���ڴ�����ʼ������" << endl;
	}
};


void test01() {
	//��һ̨�������
	CPU* intelCpu = new IntelCPU;//�����ָ��ָ������Ķ���
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	
}

int main() {
	test01();
}