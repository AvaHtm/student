#include<iostream>
#include<cstring>
using namespace std;
struct student {
	char name[10];
	float grade;
	int unit;
	int passunit;
	int fallunit;
};
void sort(student a[] , const int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].grade>a[j].grade)
			{
				student temp;
				temp.grade=a[i].grade;
				strcpy(temp.name,a[i].name);

				strcpy(a[i].name,a[j].name);
				a[i].grade=a[j].grade;

				strcpy(a[j].name,temp.name);
				a[j].grade=temp.grade;
			}
		}
	}
}
void getstudent(student & a)
{
	cin>>a.name>>a.grade>>a.unit>>a.passunit>>a.fallunit;
}
int main()
{
	int n;
	cout<<"enter a number";
	cin>>n;
	student*p,top;
	p=new student[n];
	if(p==0)
		cout<<"error";
	else{
		cout<<"enter name,unit,grade,passed,fallen"<<endl;
		cin>>p[0].name>>p[0].grade>>p[0].unit>>p[0].passunit>>p[0].fallunit;
		top=p[0];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"enter name,unit,grade,passed,fallen"<<endl;
		getstudent(p[i]);
		sort(p,n);
		if(top.passunit<p[i].passunit)
			top=p[i];
	}
	cout<<top.name<<endl;
	for(int i=0;i<n;i++)
		{
			cout<<p[i].name<<p[i].grade<<p[i].unit<<p[i].passunit<<p[i].fallunit;
		}
	delete[] p;
	return 0;
}