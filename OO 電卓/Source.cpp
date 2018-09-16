#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/*簡単な計算を同時に複数行う*/

/*
class DebugMessage {//デバッグ用のメッセージ表示
protected:
	const char *EntityName;
public:
	DebugMessage(const char *InName) { EntityName = InName; }
	void MES(const char *InMessage) { std::cout << *EntityName << " " << *InMessage<<"\n"; }
	~DebugMessage() { delete EntityName; }
};
*/
class Calculation {//計算主力部分
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
	void InitSet(double in) { this->ans = in; }//, DEBUG->MES("初期値を設定 %f"), in;}
	void Addition(double in) { this->ans += in; }//, DEBUG->MES("%fを足す",in); }
	void Subtraction(double in) { this->ans -= in; }//, DEBUG->MES("%fを引く"),in; }
	void division(double in) { if (in != 0) this->ans /= in; }//, DEBUG->MES("%fで割る"),in;}
	void Multiplicarion(double in) { this->ans *= in;}//, DEBUG->MES("%fをかける"),in; }
	void PrintAns() {std::cout << MyName<<"の答えは" << this->ans<<"\n";}//DEBUG->MES("答えは %f"),this->ans; }
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