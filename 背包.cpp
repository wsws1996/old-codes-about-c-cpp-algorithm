# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

struct goods
{
public:
	int value;
	int weight;
};

bool com(goods a,goods b)
{
    if(a.value>b.value)
        return true;
    else
        return false;
}

int main(void)
{
	vector<goods> bag;
	int dnum,gnum;
	int val,wei;
	int tweight;
	int result;
	int cnt=0,count=0;
	cin>>dnum;
	int endnum;
	int sum1=0,sum2=0;
	int temp;
	for(cnt=0;cnt<dnum;cnt++)
	{
		cin>>gnum;
		cin>>tweight;
		for(count=0;count<gnum;++count)
		{
		    cin>>val;
		    cin>>wei;
            goods t;
            t.value=val;
            t.weight=wei;
            bag.push_back(t);
		}
		sort(bag.begin(),bag.end(),com);
		for(count=0;count<bag.size();++count)
        {
            cout<<bag[count].weight<<endl;
        }
		for(count=0;count<bag.size();++count)
        {
           sum2+=bag[count].weight;
           sum1=sum2-bag[count].weight;
           if(sum1>=tweight)
                break;
        }
        count=endnum;
        if(sum1!=tweight)
        {
            temp=tweight-sum2;
            bag[endnum].weight=temp;
        }
        for(count=0;count<=endnum;++count)
        {
            result+=(bag[count].value*bag[count].weight);
        }
        cout<<result<<endl;
	}
}
