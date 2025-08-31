#include "rdb.h"

//Union definition
Relation * Union(Relation * R1,Relation *R2){
    // cout<<"hellllo";
    bool check=R1->getattrnames()!=R2->getattrnames();
    if(R1->getnattr()!=R2->getnattr()||check){
        return nullptr;
    }
    // cout<<"hello0";
    Relation *R = new Relation(R1->getattrnames());
    int flag=0;
    for(auto i:R1->getrecs()){
        R->addrecord(new Record(* i));
    }   
    for(auto frec: R2->getrecs()){
        for(auto srec: R1->getrecs()){
            flag=0;
            if(*srec==*frec){
                flag=1;
            break;
            }
            
        }
        if(flag!=1){
            R->addrecord(new Record(*frec));
            //cout<<"hello";
        }
    }
    return R;
   // Relation * output =new Relation(R);
    // R->display_table();
    //return output;
}

//Difference definition
Relation * Difference(Relation *R1,Relation * R2){ //R1-R2
    bool check=R1->getattrnames()!=R2->getattrnames();
    if(R1->getnattr()!=R2->getnattr()||check){
        return nullptr;
        // return;
    }
    int flag=0;

    Relation *R = new Relation(R1->getattrnames());
    // if(R==nullptr){
    //     cout<<"NULL"<<endl;
    // }

    for(auto frec:R1->getrecs()){
        for(auto srec:R2->getrecs()){
            flag=0;
            if(*frec==*srec){
                flag=1;
                break;
            }
        }
        if(flag!=1){
            R->addrecord(new Record(*frec));
        }
    }
    // cout<<"hello";
    // R->display_table();
    return R;

}


//cartesianproduct function
Relation * cartesianproduct(Relation *R1,Relation *R2){
    // cout<<"hello";
    vector<string>attrname=R1->getattrnames();
    // attrname.insert(attrname.end(),R2->getattrnames().begin(),R2->getattrnames().end());
    for(auto i:R2->getattrnames()){
        attrname.push_back(i);
    }
    Relation *R = new Relation(attrname);
    for(auto frec:R1->getrecs()){
        
        for(auto srec:R2->getrecs()){
            Record *new_rec=new Record((frec->getvecattr()));
            for(auto attr:srec->getvecattr()){
                new_rec->addattr(attr);
            }
            R->addrecord(new_rec);
        }
        
    }
    return R;


}

//projection function
Relation * projection(Relation * R1,list<string>projectattrs){
    vector<bool>check(R1->getnattr(),false);
    vector<string>attrnames;
    int i=0;
    for(auto attrs:R1->getattrnames()){
        for(auto proattrs: projectattrs){
            if(attrs==proattrs){
                attrnames.push_back(attrs);
                check[i]=true;
                break;
            }
        }
        i++;
    }

    Relation *R=new Relation(attrnames);
    for(auto rec:R1->getrecs()){
        i=0;
        vector<Attr *> new_vec;
        for(auto attr: rec->getvecattr()){
            if(check[i]){
                new_vec.push_back(attr);
            }
            i++;
        }
        Record * new_rec=new Record(new_vec);
        R->addrecord(new_rec);
    }

    return R;
}

//Renaming the Attribute name within the relation itself
Relation * Rename(Relation *R,string s1,string s2){
    int ind=R->getAttrInd(s1);
    R->renameattrname(ind,s2);
    return R;
}


bool eval(tuple<string,char, Attr*> formula,Record* r,Relation* R){//checks for the particular condition

    for(auto str: R->getattrnames()){
        //cout<<"Attr- "<<str<<" ";
        //cout<<get<0>(formula)<<endl;
        //cout<<get<1>(formula)<<endl;
        if(get<0>(formula)==str){
            //cout<<"Match found"<<endl;
            if(get<1>(formula)=='='){
                //cout<<"Match found2"<<endl;
                if(*(r->getattr(R->getAttrInd(str)))==*(get<2>(formula))){
                    cout<<"returning true"<<endl;
                    return true;
                }
            }
            else if(get<1>(formula)=='<'){
                if(*r->getattr(R->getAttrInd(str))<*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='>'){
                if(*r->getattr(R->getAttrInd(str))>*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='1'){
                if(*r->getattr(R->getAttrInd(str))>=*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='0'){
                if(*r->getattr(R->getAttrInd(str))<=*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='!'){
                if(*r->getattr(R->getAttrInd(str))!=*get<2>(formula)){
                    return true;
                }
            }
            else return false;
        }
    }
    return false;
}

bool DNFCheck(DNFformula *f,Relation* R,Record* rec){//Checks for DNF formula
    bool ans_f= false;
   
    for(auto r: f->ops){
        bool ans= true;
        for(auto s: r){
            if(eval(s,rec,R)==false){
                ans=false;
                break;
            }
        }
        if(ans==true){
            ans_f=true;
            break;
        }
    }
    return ans_f;
}

Relation* Rselection(Relation* R1, DNFformula *f){//Selects in relation depending on the conditions
    Relation* R = new Relation(R1->getattrnames());
    for(auto r : R1->getrecs()){
        if(DNFCheck(f,R1,r)){
            R->addrecord(new Record(*r));
        }
    }
    return R;
}


