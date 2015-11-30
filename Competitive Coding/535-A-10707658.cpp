#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number;
    int first_digit;
    int second_digit;
    while(cin>>number){
    if(number==0) {cout<<"zero";continue;}
    first_digit = number/10;
    second_digit = number%10;
    if(number >= 11 && number <= 20)
    {
        switch(number)
        {
            case 11:
                cout<<"eleven";
                break;

            case 12:
                cout<<"twelve";
                break;
            case 13:
                cout<<"thirteen";
                break;
            case 14:
                cout<<"fourteen";
                break;
            case 15:
                cout<<"fifteen";
                break;
            case 16:
                cout<<"sixteen";
                break;
            case 17:
                cout<<"seventeen";
                break;
            case 18:
                cout<<"eighteen";
                break;
            case 19:
                cout<<"nineteen";
                break;
            case 20:
                cout<<"twenty";
                break;
        }
    }
    else
    {
        switch(first_digit)
        {
            case 1:
                if(second_digit == 0)
                    cout<<"ten";
                break;
            case 2:
                cout<<"twenty";
                break;
            case 3:
                cout<< "thirty";
                break;
            case 4:
                cout<<"forty";
                break;
            case 5:
                cout<<"fifty";
                break;
            case 6:
                cout<<"sixty";
                break;
            case 7:
                cout<<"seventy";
                break;
            case 8:
                cout <<"eighty";
                break;
            case 9:
                cout <<"ninety";
                break;
            case 10:
                cout <<"one hundred";
                break;
        }
        if(first_digit > 1 && number != 100&&second_digit!=0) cout<<"-";
        switch(second_digit)
        {
            case 1:
                cout<<"one";
                break;
            case 2:
                cout<<"two";
                break;
            case 3:
                cout<<"three";
                break;
            case 4:
                cout<<"four";
                break;
            case 5:
                cout<<"five";
                break;
            case 6:
                cout<<"six";
                break;
            case 7:
                cout<<"seven";
                break;
            case 8:
                cout<<"eight";
                break;
            case 9:
                cout<<"nine";
                break;
            default:
                break;

        }
    }}
    return 0;
}