#include <bits/stdc++.h>

using namespace std;

int N;
int start;
int cnt;
int ok;
struct piatra
{
    queue<int> jump;
    int num_salt;
};
vector<piatra> pietre;
vector <int> copie_subset;
void read_input()
{
    cin>>N;
    cin>>start;

  //  cout<<"N si start: "<<N<<' '<<start<<"\n";
    pietre.resize(N);
    int nr_jumps;
    int subseti;
    for (int i =0; i<N - 1; i++)
    {
        cin>>nr_jumps;
       // cout<<"Nr jumps: "<<nr_jumps<<' ';
        pietre[i].num_salt = nr_jumps;
      //  pietre[i].jump.resize(nr_jumps);
        for (int j =0; j<nr_jumps; j++)
            {cin>>subseti;
            pietre[i].jump.push(subseti);
           // cout<<pietre[i].jump.front()<<' ';
            }
          //  cout<<"\n";
     }

}
void copy_elem(int nr, vector <int> &original)
{
    copie_subset.resize(nr);
    for (int i = 0; i<nr; i++)
    {
        copie_subset[i] = original[i];
    }
}
int main()
{   
    read_input();

    //cout<<"AM CITT"<<"\n";
    if (start >= N)
    {
        return -1;
    }
    while (start < N && ok != -1)
    {   
       // cout<<"START: "<<pietre[start].jump.front()<<"\n";
         if (pietre[start].num_salt == 1)
        {   
           // cout<<"sum: "<<start + pietre[start].jump.front()<<"\n";
            if (start + pietre[start].jump.front() > N - 1)
            ok = -1;
                //return -1;
            else 
            {start = start + pietre[start].jump.front();
           // continue;
            }
                
        }
        else {
            if (pietre[start].num_salt == 2)
            {
               // cout<<"SUNT PE 2"<<"\n";
                int jump1, jump2;
                if (start+ pietre[start].jump.front() > N - 1)
                {
                    jump1 = -1;
                    pietre[start].jump.pop();
                }
               else {
                jump1 = pietre[start].jump.front();
                pietre[start].jump.pop();
               }
            //jump2
               if (start + pietre[start].jump.front() > N - 1)
               {
                jump2 = -1;
                pietre[start].jump.pop();
               }
               else {
                jump2 = pietre[start].jump.front();
                pietre[start].jump.pop();
               }

               if (jump1 == -1 && jump2 == -1)
               {
                ok = -1;
               // return -1;
               }
              // cout<<"j1 j2 : "<<jump1<<' '<<jump2<<"\n";
               if (jump1 != -1 && jump2 == -1)
               {
                start = start + jump1;
                cnt++;
               // cout<<"val start jmp1"<<start<<"\n";
                //continue;
               }
               if (jump1 == -1 && jump2 != -1)
               {
                start = start + jump2;
                cnt++;
               // continue;
               }
                if (jump1 != -1 && jump2 != -1)
                {
                    //int max = 0;

                    int var1 = start + jump1;
                    int var2 = start + jump2;
                
                    if (var1 > var2)
                    {
                        start = var1;
                    }
                    else start = var2;
                    cnt++;
                    //cout<<"START DIN ALA: "<<start<<"\n";
                    continue;
                }

            }
            else {
                if (pietre[start].num_salt == 3)
                {
                    int jump1, jump2, jump3;

                    if (start+ pietre[start].jump.front() > N - 1)
                {
                    jump1 = -1;
                    pietre[start].jump.pop();
                }
               else {
                jump1 = pietre[start].jump.front();
                pietre[start].jump.pop();
               }
            //jump2
               if (start + pietre[start].jump.front() > N - 1)
               {
                jump2 = -1;
                pietre[start].jump.pop();
               }
               else {
                jump2 = pietre[start].jump.front();
                pietre[start].jump.pop();
               }

               if (start + pietre[start].jump.front() > N - 1)
               {
                jump3 = -1;
                pietre[start].jump.pop();
               }
               else {
                jump3 = pietre[start].jump.front();
                pietre[start].jump.pop();
               }

               if (jump1 == -1 && jump2 == -1 && jump3 == -1)
               {
                ok = -1;
                //return -1;
               }
               if (jump1 != -1 && jump2 == -1 && jump3 == -1)
               {
                start = start + jump1;
                cnt++;
                //continue;
               }
               if (jump1 == -1 && jump2 != -1 && jump3 == -1)
               {
                start = start + jump2;
                cnt++;
                continue;
               }
                
                
                    //int max = 0;

                    int var1 = start + jump1;
                    int var2 = start + jump2;
                    int var3 = start + jump3;

                    vector <int> local;
                    local.resize(3);

                    local.push_back(var1);
                    local.push_back(var2);
                    local.push_back(var3);
                    auto max = max_element(local.begin(), local.end());

                    int val = *max;
                    start = val;
                    cnt++;
                   continue;
                

                }
            }
        }
       
    }
    if (ok == -1)
    cout<<-1;
   else  cout<<cnt;
     return 0;
 }