#include "rdb.h"


Relation* NaturalJoin(Relation* R1,Relation* R2){
    vector<string> attrnames;
    vector<tuple<int,int>> common_attr;  // common attr indices in R1 and R2
    int flag=0;
    for(auto s : R1->getattrnames()){
        for(auto s1 : R2->getattrnames()){
            if(s == s1){
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        return nullptr;
    }
    else{
        for(auto s : R1->getattrnames()){
            attrnames.push_back(s);
        }
        int i,j;
        i=j=0;
        for(auto s : R2->getattrnames()){
           flag=1;
           i=0;
           for(auto s1 : R1->getattrnames()){
               if(s == s1){
                   flag=0;
                   
                   tuple<int,int>temp;
                   temp={i,j};
                   common_attr.push_back(temp);
               }
               
               i++;
           }
           if(flag==1){
                attrnames.push_back(s);
            }
           j++;
        } 
        Relation* R = new Relation(attrnames);
        for(auto r1 : R1->getrecs()){
            for(auto r2 : R2->getrecs()){
                flag=1;
                for(auto t : common_attr){
                    if(*(r1->getattr(get<0>(t))) != *(r2->getattr(get<1>(t)))){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    vector<Attr*> attrs;
                    for(int i=0; i<R1->getnattr(); i++){
                        attrs.push_back(r1->getattr(i));
                    }
                    for(int i=0; i<R2->getnattr(); i++){
                        for(auto j: common_attr){
                            if(i!=get<1>(j))
                            attrs.push_back(r2->getattr(i));
                        }
                    }
                    R->addrecord(new Record(attrs));
                }
            }
        }
        return R;
    }
}
