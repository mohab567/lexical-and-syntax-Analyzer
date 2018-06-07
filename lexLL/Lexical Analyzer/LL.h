#ifndef LL__h
#define LL__h
#include <iostream>   // std::cout
#include <string>
class LL
{
public:
    LL()
    {}
    map<string,vector<string>> makeLL(map<string,vector<string>> split)
    {
//LL
// 1- replacement
        for(map<string,vector<string>>::iterator itr = split.begin() ; itr !=split.end(); itr++)
        {
            int first ;
            for(map<string,vector<string>>::iterator itr2 = split.begin() ; itr2!=itr  ; itr2++)
            {
                for(int i =0; i< (itr->second).size(); i++)
                {
                    string s = (itr->second)[i];
                    if(itr2->first == s.substr(0,findfirst(s,' ')))
                    {
                        (itr->second).erase((itr->second).begin()+i);
                        i--;
                        string scut = s.substr((itr2->first).length(),s.length());
                        for(int j =0; j< (itr2->second).size(); j++)
                        {
                            if((itr2->second)[j]!= "\\L")
                            {
                                (itr->second).push_back((itr2->second)[j]+scut);
                            }
                            else
                            {
                                (itr->second).push_back(scut.substr(1,scut.length()));
                            }
                        }
                    }

                }
            }
            //imediate elemenation
            first = 0;
            vector<string> v;

            for(int i =0; i< (itr->second).size(); i++)
            {

                if(itr->first== (itr->second)[i].substr(0,findfirst((itr->second)[i],' ')) )
                {

                    if(first==0)
                    {
                        v.push_back("\\L");
                        split.insert(make_pair((itr->first)+'\'', v));
                        first=1;


                    }
                    string s= (itr->second)[i];
                    (itr->second).erase(((itr->second).begin()+i));
                    i--;
                    map<string,vector<string>>::iterator got = split.find ((itr->first)+'\'');
                    if(s.length()==(itr->first).length())
                    {
                        cout<<"grammer is ambigous";
                        exit(0);
                    }
                    (got->second).push_back(s.substr((itr->first).length()+1,s.length())+" "+(itr->first)+'\'');

                }

                //---
            }
            //---
            if(first!=0)
            {
                for(int i =0; i< (itr->second).size(); i++)
                {

                    if((itr->second)[i]!="\\L")
                    {
                        (itr->second)[i]=(itr->second)[i]+" "+(itr->first)+'\'';

                    }
                    else
                    {
                        (itr->second)[i]=(itr->first)+'\'';

                    }

                }


            }


        }


//-----------printing left recursion
/*
        for(map<string,vector<string>>::iterator itr = split.begin() ; itr !=split.end(); itr++)
        {
            cout<<itr->first<<"======="<<endl;
            for(int i =0; i< (itr->second).size(); i++)
            {
                cout<<(itr->second)[i]<<endl;


            }

        }

*/
//------------


//left factoring
        for(map<string,vector<string>>::iterator itr = split.begin() ; itr !=split.end(); itr++)
        {


            for(int i=0; i<(itr->second).size()-1; i++)
            {
                vector<string> temp;
                int first=0;
                for(int j =i+1; j<(itr->second).size(); j++)
                {


                    if((itr->second)[i].substr(0,findfirst( (itr->second)[i] ,' '))==(itr->second)[j].substr(0,findfirst((itr->second)[j],' ')))
                    {


                        if(first==0)
                        {
                            string s=(itr->second)[i].substr(findfirst( (itr->second)[i] ,' ') , (itr->second)[i].length());
                            if(s.length()==0)
                            {
                                s="\\L";
                            }
                            else
                            {
                                s=s.substr(1,s.length());
                            }
                            temp.push_back(s);
                            split.insert(make_pair((itr->first)+toString(i)+'\'', temp));
                            first=1;
                        }
                        map<string,vector<string>>::iterator got = split.find ((itr->first)+toString(i)+'\'');

                        string s=(itr->second)[j].substr(findfirst( (itr->second)[j] ,' ') , (itr->second)[j].length());

                        if(s.length()==0)
                        {
                            s="\\L";
                        }
                        else
                        {
                            s=s.substr(1,s.length());
                        }
                        (got->second).push_back(s);
                        (itr->second).erase((itr->second).begin()+j);
                        j--;

                    }
                    if(first==1)
                    {
                        (itr->second)[i]=(itr->second)[i].substr(0,findfirst( (itr->second)[i] ,' '))+" "+(itr->first)+toString(i)+'\'';
                    }

                }



            }



        }

//--------------- testing left factoring
/*
        cout<<"cccccccccccccccccc"<<endl<<endl;
        for(map<string,vector<string>>::iterator itr = split.begin() ; itr !=split.end(); itr++)
        {
            cout<<itr->first<<"======="<<endl;
            for(int i =0; i< (itr->second).size(); i++)
            {
                cout<<(itr->second)[i]<<endl;


            }

        }
     cout<<"ccccccccccccccccc"<<endl<<endl;

*/
//----------------

        return split;
    }
    int findfirst(string s,char h)
    {
        int i=0;
        for( i=0; i<s.length(); i++)
        {
            if(s.at(i)==h)
            {
                return i;
            }

        }
        return i;
    }
    string toString(int s)
    {
        ostringstream convert;   // stream used for the conversion

        convert << s;      // insert the textual representation of 'Number' in the characters in the stream

        return convert.str();
    }

};


#endif
