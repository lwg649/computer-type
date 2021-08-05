#include<iostream>
using namespace std;

//抽象不同零件类
//抽象CPU类

class CPU{
public:
	//抽象计算函数
	virtual void  calculate() = 0;

};

//抽象显卡类
class VideoCard {
public:
	virtual void display () = 0;
};

//抽象内存条
class Memory{
public:
	virtual void storage() = 0;
};

//电脑类
class Computer{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void work() {
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//提供析构函数  释放三个电脑的零件
	~Computer() {
		//释放CPU零件
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
	CPU* m_cpu;//cpu 的零件指针
	VideoCard* m_vc;//显卡零件指针
	Memory* m_mem;//内存条零件指针
};


//具体的厂商
//Intel
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Inter的cpu开始计算了" << endl;
	}
};

class IntelVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Intel的显卡开始工作了" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel的内存条开始储存了" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << " Lenovo的cpu开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "Lenovo的显卡开始工作了" << endl;
	}
};
class  LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << " Lenovo的内存条开始储存了" << endl;
	}
};


void test01() {
	//第一台电脑零件
	CPU* intelCpu = new IntelCPU;//父类的指针指向子类的对象
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	
}

int main() {
	test01();
}