#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/*�ȒP�Ȍv�Z�𓯎��ɕ����s��*/

/*
class DebugMessage {//�f�o�b�O�p�̃��b�Z�[�W�\��
protected:
	const char *EntityName;
public:
	DebugMessage(const char *InName) { EntityName = InName; }
	void MES(const char *InMessage) { std::cout << *EntityName << " " << *InMessage<<"\n"; }
	~DebugMessage() { delete EntityName; }
};
*/
class Calculation {//�v�Z��͕���
protected:
	double ans;
	const char *MyName = NULL;
	//DebugMessage *DEBUG;
public:
	Calculation(const char * InName) { 
		ans = 0;
		MyName = InName;
		//DEBUG = new DebugMessage(MyName);
	}
	void InitSet(double in) { this->ans = in; }//, DEBUG->MES("�����l��ݒ� %f"), in;}
	void Addition(double in) { this->ans += in; }//, DEBUG->MES("%f�𑫂�",in); }
	void Subtraction(double in) { this->ans -= in; }//, DEBUG->MES("%f������"),in; }
	void division(double in) { if (in != 0) this->ans /= in; }//, DEBUG->MES("%f�Ŋ���"),in;}
	void Multiplicarion(double in) { this->ans *= in;}//, DEBUG->MES("%f��������"),in; }
	void PrintAns() {std::cout << MyName<<"�̓�����" << this->ans<<"\n";}//DEBUG->MES("������ %f"),this->ans; }
	~Calculation() {;}
};

int main() {
	Calculation *I = new Calculation("I");
	Calculation *J = new Calculation("J");
	Calculation *K = new Calculation("K");

	I->InitSet(3.7);
	J->InitSet(10);
	I->Addition(3.66);
	K->InitSet(142);
	J->Multiplicarion(5.36);
	K->Subtraction(-34);
	I->division(1.22);
	J->Addition(90);

	I->PrintAns();
	J->PrintAns();
	K->PrintAns();
	delete I, J, K;
	return 0;
}