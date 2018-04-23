#include<iostream>
using namespace std;

class base {

protected:
	int x;
public:
	int test_field_overshadow;
	
	base(int i):test_field_overshadow(35) {
		this->x = i;
		cout << "in base:"<<x<<"\n";
	}
	base() {
		cout << "in base default constructor:\n";
	}
	int get_x() {
		return this->x;
	}

	void set_x(int _x) {
		this->x = _x;
	}

	
};

class derived_1 : virtual public base {
protected:
	int d1;
	int test_a;
public:
	int test_field_overshadow;

	derived_1() :base(10), d1(0),test_a(200), test_field_overshadow(45) {
		cout << "in derived_1\n";
	}
	int get_d1() {
		return this->d1;
	}
	void set_d1(int _d1) {
		this->d1 = _d1;
	}

};

class derived_2 :virtual  public base {
protected:
	int d2;
	int test_a;
public:
	derived_2() :base(20), d2(0), test_a(400) {
		cout << "in derived_2\n";
	}
	int get_d2() {
		return this->d2;
	}
	void set_d2(int _d2) {
		this->d2 = _d2;
	}
};

class derived_3 : public derived_1, public derived_2 {
protected:
	int d3;
public:
	derived_3():base(100){
		cout << "in derived_3\n";
	}
	int get_d3() {
		return this->d3;
	}
	void set_d3(int _d3) {
		this->d3 = _d3;
	}

	//the following reference to test_a is ambiguous
	/*int get_test_a() {
		return test_a;
	}*/
};

int main() {
	derived_3 ob3;
	//ob3.set_x(0);
	ob3.set_d1(1);
	ob3.set_d2(2);
	ob3.set_d3(3);
	cout << ob3.get_x();

	//the following snippet tests field overshadow
	base *bp;
	bp = new base(-1);
	cout << bp->test_field_overshadow << endl;

	bp = new derived_1();
	cout << bp->test_field_overshadow << endl;
	cout << "--------- both test_field_overshadow returning 35------------" << endl;

	derived_1 ob;
	cout << ob.test_field_overshadow << endl;
	cout << "--------- Now test_field_overshadow returning 45------------" << endl;



	getchar();
	return 0;
}

