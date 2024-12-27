#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>


int main()
{
    auto comp=[](const std::vector<std::string> &a, const std::vector<std::string> &b)->bool{
        for(size_t i=0;i<a.size();i++)
        {
            if (std::stoi(a[i]) != std::stoi(b[i])) 
            {
                return std::stoi(a[i]) < std::stoi(b[i]);
            }
        }
        return false;
    };
    
    std::vector<std::vector<std::string>> m; 
    std::string line;
    std::ifstream in("D:\\programming2\\Lab_2\\ip_filter.tsv");
    while(std::getline(in,line))
    {
        int start=0;
        long long unsigned int last=line.find_first_of('\t');
        std::string ed_line=line.substr(start,last);
        std::vector<std::string> info;
        last=ed_line.find_first_of('.');
        while(last!= std::string::npos)
        {
            info.push_back(ed_line.substr(start, last - start));
            start=last+1;
            last=ed_line.find_first_of('.',start);
        }
        info.push_back(ed_line.substr(start));
        m.push_back(info);
    }
    std::sort(m.begin(),m.end(),comp);
    for(auto spis:m)
    {
        std::cout<<spis[0]<<"."<<spis[1]<<"."<<spis[2]<<"."<<spis[3]<<std::endl;
    }

    //std::cout<<"__________________________________________________________________"<<std::endl;
    for(auto adress:m)
    {
        if(adress[0]=="1")
        {
            std::cout<<adress[0]<<"."<<adress[1]<<"."<<adress[2]<<"."<<adress[3]<<std::endl;
        }
    }

    //std::cout<<"__________________________________________________________________"<<std::endl;
    for(auto adress:m)
    {
        if(adress[0]=="46"&&adress[1]=="70")
        {
            std::cout<<adress[0]<<"."<<adress[1]<<"."<<adress[2]<<"."<<adress[3]<<std::endl;
        }
    }

    //std::cout<<"__________________________________________________________________"<<std::endl;
    for(auto adress:m)
    {
        if(adress[0]=="46"||adress[1]=="46"||adress[2]=="46"||adress[3]=="46")
        {
            std::cout<<adress[0]<<"."<<adress[1]<<"."<<adress[2]<<"."<<adress[3]<<std::endl;
        }
    }

}
