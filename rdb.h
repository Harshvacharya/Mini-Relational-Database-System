#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<tuple>

using namespace std;

class Attr{
    public:

    virtual bool operator==(const Attr& right)=0;
    virtual bool operator>(const Attr& right)=0;
    virtual bool operator<(const Attr& right)=0;
    virtual bool operator!=(const Attr& right)=0;
    virtual bool operator>=(const Attr& right)=0;
    virtual bool operator<=(const Attr& right)=0;
};

//derived classes
class integerAttribute:public Attr{
    int val;
    public:
    integerAttribute(int value):val(value){}  //Constructor
    //Operators overlaoding in derived class
    
    bool operator==(const Attr&right)override;
    

    bool operator>(const Attr& right)override;
    

    bool operator<(const Attr& right)override;
    

    bool operator!=(const Attr& right)override;
    

    bool operator>=(const Attr& right)override;
    

    bool operator<=(const Attr& right)override;
    

    //methods to access attributes
    int getval()const{
        return this->val;
    }
    void setval(int value){
        this->val=value;
    }
};

class floatAttribute:public Attr{
    float val;
    public:
    floatAttribute(float value):val(value){}//Constructor

    //Operators overlaoding in derived class
    
    bool operator==(const Attr&right)override;
    

    bool operator>(const Attr& right)override;
    

    bool operator<(const Attr& right)override;
    

    bool operator!=(const Attr& right)override;
    

    bool operator>=(const Attr& right)override;
    

    bool operator<=(const Attr& right)override;
    

    //methods to access attributes
    float getval()const{
        return this->val;
    }
    void setval(int value){
        this->val=value;
    }
};

class stringAttribute:public Attr{
    string val;
    public:
    stringAttribute(string value):val(value){}//Constructor
    //Operators overlaoding in derived class
    
    bool operator==(const Attr&right)override;
    

    bool operator>(const Attr& right)override;
    

    bool operator<(const Attr& right)override;
    

    bool operator!=(const Attr& right)override;
    

    bool operator>=(const Attr& right)override;
    

    bool operator<=(const Attr& right)override;
    
    //methods to access attributes
    string getval()const{
        return this->val;
    }
    void setval(string value){
        this->val=value;
    }
};

class Record {
    vector<Attr *>attrptr;

    public:
    Record(vector<Attr *>attr_vec):attrptr(attr_vec){ ///Assuming that we are allocating spaces by new to Attr*
        
    }

    ~Record(){}


    void addattr(Attr *attr){
        attrptr.push_back(attr);
    }
    Attr * getattr(int index){
        return attrptr[index];
    }

    vector<Attr*> getvecattr(){
        return attrptr;
    }

    bool operator==(const Record& rec){
        if(rec.attrptr.size()!=attrptr.size()){
            return false;
        }
        else{
            for(int i=0;i<attrptr.size();i++){
                if(*(rec.attrptr[i])!=*attrptr[i]){
                    return false;
                }
            }
        }
        return true;
    }

};



class Relation{

    vector <string>attrnames;
    int nattr,nrecs;
    vector <int> attrinds;
    list <Record *> recs;

    public:
    Relation(vector<string>names):nattr(names.size()),attrnames(names){ //Constructor
        this->nrecs=0;
        attrinds.resize(nattr);
        for(int i=0;i<nattr;i++){
            attrinds.push_back(i);
        }

    }
    ~Relation(){    //Destructor
        
    }

    //Copy Operator
    Relation(const Relation& R):nattr(R.nattr),nrecs(R.nrecs),attrnames(R.attrnames),attrinds(R.attrinds){
        for(auto i:R.recs){
            Record * new_rec= new Record(*i);
            this->recs.push_back(new_rec);
        }
    }

    //Assignement Operator
    Relation& operator=(const Relation& R){
        this->nattr=R.nattr;
        this->nrecs=R.nrecs;
        this->attrinds=R.attrinds;
        this->attrnames=R.attrnames;

        for(auto i: this->recs){
            delete i;
        }
        this->recs.clear();
        for(auto i: R.recs){
            Record * new_rec=new Record(*i);
            this->recs.push_back(new_rec);
        }
        return *this;

    }

    list<Record *> getrecs(){
        return this->recs;
    }

    vector<string> getattrnames(){
        return attrnames;
    }

    int getnattr(){
        return nattr;
    }
    void renameattrname(int ind, string s){
        attrnames[ind]=s;
    }
    int getnrecs(){
        return nrecs;
    }
    void addrecord(Record * r){
        nrecs++;
        recs.resize(nrecs);
        list<Record *>::iterator it = recs.begin();
  
    // Move the iterator by 5 elements
        advance(it,nrecs-1);
        *it=r;
        
    }
    
    int getAttrInd(string str){
        int res=0;
        for(auto i: attrnames){
            if(i==str){
                return res;
            }
            res++;
        }
        return -1;
    }

    void delete_table(){
        for(auto i: this->recs){
            delete i;
        }
        this->recs.clear();
        this->nrecs=0;
        cout<<"Successfully deleted"<<endl;
    }

    void display_table(){
        for(auto i: attrnames){
            cout<<i<<'\t'<<'\t';
        }
        cout<<endl;
        for(auto i: recs){
            for(int j=0;j<nattr;j++){
                Attr* curr_attr=i->getattr(j);
                if((dynamic_cast<integerAttribute *>(curr_attr))!=nullptr){
                    cout<<dynamic_cast<integerAttribute *>(curr_attr)->getval()<<'\t'<<'\t';
                }
                else if((dynamic_cast<floatAttribute *>(curr_attr))!=nullptr){
                    cout<<dynamic_cast<floatAttribute *>(curr_attr)->getval()<<'\t'<<'\t';
                }
                else if(dynamic_cast<stringAttribute *>(curr_attr)!=nullptr){
                    cout<<dynamic_cast<stringAttribute *>(curr_attr)->getval()<<'\t'<<'\t';
                }
            }
            cout<<endl;
        }
    }
};

struct DNFformula{ 
    list <list <tuple <string, char, Attr *> > > ops; 
};

Relation * Union(Relation * R1,Relation *R2);
Relation * Difference(Relation *R1,Relation * R2);
Relation * cartesianproduct(Relation *R1,Relation *R2);
Relation * projection(Relation * R1,list<string>projectattrs);
Relation * Rename(Relation *R,string s1,string s2);
bool eval(tuple<string,char, Attr*> formula,Record* r,Relation* R);
bool DNFCheck(DNFformula *f,Relation* R,Record* rec);
Relation* Rselection(Relation* R1, DNFformula *f);
Relation* NaturalJoin(Relation* R1,Relation* R2);
