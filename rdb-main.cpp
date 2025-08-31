#include"rdb.h"

class interface
{
private:
    int ntables;
    vector<Relation *> tables;

public:
    interface() {ntables=0;} //initialize ntables as 0 as zero tables initially
    ~interface() {}

    void view(){ //toview all the table states including number of rows and columns
        cout << "Table no.\tNo. of records\tNo. of attributes" << endl;
        for (int i = 0; i < ntables; i++)
        {
            cout<<"\t"<<i + 1 << "\t\t" << tables[i]->getnrecs() << "\t\t" << tables[i]->getnattr() << endl;
        }
    } 
    void home()//To view, modify and operate on table
    {   cout<<endl<<endl;
        cout << "*******Home*******" << endl;
        cout<<"";
        cout << "1. View and modify your tables" << endl;
        cout << "2. Operate on tables (Relation)" << endl;
        cout << "3. Exit" << endl;

        int opt;
        cin >> opt;
        switch (opt)
        {
        case 1:
            bag();
            break;

        case 2:
            operate();
            break;

        case 3:
            exit(0);
            break;

        default:
            cout<<"Enter Vaid Number :)"<<endl;
            home();
            break;
        }
    }

    void bag()//to view and modify table
    {   cout<<endl<<endl;
        cout << "*********OPERATION*********" << endl;
        cout << "1. View your tables" << endl;
        cout << "2. Create a table" << endl;
        cout << "3. Delete a table" << endl;
        cout << "4. Add a record to a table" << endl;
        cout << "5. Print a table" << endl;
        cout << "6. Home" << endl;

        int opt;
        int no;
        vector<string> attrnames;
        vector<Attr *> attr;
        int nattr;
        cin >> opt;
        switch (opt)
        {
        case 1:
        {   if(ntables==0){
            cout<<"No tables to views, First Create Tables"<<endl;
            home();
            break;

            }
            else{
            view();
            home();
            break;
            }
        }

        case 2:

        {   cout<<"Table no."<<ntables+1<<" Would be created"<<endl;
            cout << "Enter the number of attributes" << endl;
            cin >> nattr;

            for (int i = 0; i < nattr; i++)
            {
                string temp;
                cout << "Enter the name of attribute no. " << i + 1 << endl;
                cin >> temp;
                attrnames.push_back(temp);
            }
            Relation temp(attrnames);
            tables.push_back(&temp);
            cout << "An empty table was created.\n Table no.: "<< ntables+1 << endl;
            ++ntables;
            home();
            break;
        }

        case 3:
        {   view();
            cout << "Enter the table no. to be deleted" << endl;

            cin >> no;
            tables.erase(tables.begin() + no - 1);
            --ntables;
            home();
            break;
        }

        case 4:
        {   view();
            cout << "Enter the table no. to be operated" << endl;
            // int no;
            cin >> no;
            cout << "Enter the record to be added" << endl;
            vector<Attr*> temp_attr;
            for (int i = 0; i < tables[no - 1]->getnattr(); i++)
            {
                cout<< "Attribute Name: "<<tables[no - 1]->getattrnames()[i] << "\n";
                cout<<"Enter the type of attribute(int,string,float): ";
                string type;
                cin >> type;
                cout<<"Enter the value of attribute: ";
                if(type == "int"){
                    int tempInt;
                    cin >> tempInt;
                    temp_attr.push_back(new integerAttribute(tempInt));
                }
                else if(type == "float"){
                    float tempFloat;
                    cin >> tempFloat;
                    temp_attr.push_back(new floatAttribute(tempFloat));
                }
                else if(type == "string"){
                    string tempStr;
                    cin >> tempStr;
                    temp_attr.push_back(new stringAttribute(tempStr));
                }
                else{
                    cout<<"Invalid type. Try again.\n";
                    --i;
                }
                
            }
            Record *rec = new Record(temp_attr);
            tables[no - 1]->addrecord(rec);
            home();
            break;
        }

        case 5:
        {   view();
            cout << "Enter the table no. to be printed (choose only from the above existing tables)" << endl;
            cin >> no;
            tables[no - 1]->display_table();
            home();
            break;
        }

        case 6:
            home();

        default:
            home();
        }
    }

    void operate()//to perform operations
    {
        cout << "Welcome to Relational Database Management System ++" << endl;
        cout << "1. Union" << endl;
        cout << "2. Difference" << endl;
        cout << "3. Cartesian Product" << endl;
        cout << "4. Projection" << endl;
        cout << "5. Selection" << endl;
        cout << "6. Rename" << endl;
        cout << "7. Natural Join" << endl;
        cout << "8. Home" << endl;

        int opt;
        int a, b;
        cin >> opt;
        list<string> pro;
        switch (opt)
        {
        case 1:
            {
                cout << "Enter the table nos. of whose union is to be generated" << endl;
                view();
            cin >> a >> b;
            Relation *R = Union(tables[a - 1], tables[b - 1]);
            if(R==nullptr){
                cout<<endl<<"Can't find Union"<<endl;
                home();
                break;
            }
            else{
            R->display_table();
            tables.push_back(R);
            
            ntables++;
            cout<<"Table no. "<<ntables<<" has been created by this Union action"<<endl;
            home();
            break;
            }

            }
        case 2:
           {
             cout << "Enter the table nos. of whose difference is to be generated" << endl;
            view();
            cin >> a >> b;
            Relation *R1 = Difference(tables[a - 1], tables[b - 1]);
            if(R1==nullptr){
                cout<<endl<<"Can't find Difference"<<endl;
                home();
                break;
            }
            else{
            R1->display_table();
            tables.push_back(R1);
            ntables++;
            cout<<"Table no. "<<ntables<<" has been created by this Difference action"<<endl;
            home();
            break;
           }
           }

        case 3:
           {
             cout << "Enter the table nos. of whose cartesian product is to be generated" << endl;
             view();
            cin >> a >> b;
            Relation *R2 = cartesianproduct(tables[a - 1], tables[b - 1]);
            R2->display_table();
            tables.push_back(R2);
            ntables++;
            cout<<"Table no. "<<ntables<<" has been created by this CartesianProduct action"<<endl;

            home();
            break;
           }

        case 4:
           { 
             cout << "Enter the input table no. whose projection is to be taken: " << endl;
             view();
            int a;
            cin >> a;
            int b;
            cout<<"No. of attributes to be included in the projection: ";
            cin>>b;
            cout<<endl<<"Attribute Names in the current Table: ";
            for(auto name: tables[a-1]->getattrnames()){
                cout<<name<<" ,";
            }
            cout << "Enter the attributes to be projected (from the above written Attribute Names): )";
            

            
            for (int i = 0; i < b; i++)
            {
                string temp;
                cin >> temp;
                pro.push_back(temp);
            }
            Relation *R3 = projection(tables[a - 1], pro);
            R3->display_table();
            tables.push_back(R3);
            ntables++;
            home(); 
            break;
           }

        case 5:
           {
             cout << "Enter the input table no. whose selection is to be taken: " << endl;
             view();
            int a1;
            cin >> a1;
            cout<< "Enter the number of Disjunctive conditions in the DNF formula: ";
            int n2;
             DNFformula f;
            cin>>n2;
            for(int j=0; j<n2; j++){
                cout<<"Enter the number of conjunctive clauses (AND) in the "<<j+1<<"th disjunctive clause (OR):";
                int n1;
                cin>>n1;
                list <tuple<string, char, Attr*>> conj;
                for(int i=0; i<n1; i++){
                cout<<"Enter the "<<i+1<<"th conjunctive clause: "<<endl;
                tuple <string, char, Attr* > temp;
                cout<<"Enter the attribute name: ";
                string s;
                cin>>s;
                get<0>(temp)=s;
                cout<<"Enter the operator: ";
                char c;
                cin>>c;
                get<1>(temp)=c;
                cout<<"Enter the object type(string/float/int): ";
                string s1;
                cin>>s1;
                if(s1=="string"){
                    cout<<"Enter the string value: ";
                    string s2;
                    cin>>s2;
                    get<2>(temp)=new stringAttribute(s2);
                }
                else if(s1=="float"){
                    cout<<"Enter the float value: ";
                    float f;
                    cin>>f;
                    get<2>(temp)=new floatAttribute(f);
                }
                else if(s1=="int"){
                    cout<<"Enter the int value: ";
                    int i_val;
                    cin>>i_val;
                    get<2>(temp)=new integerAttribute(i_val);
                }
                conj.push_back(temp);
            }

            f.ops.push_back(conj);
            }

            for(auto i: f.ops){
                for(auto j: i){

                    cout<<get<0>(j)<<" "<<get<1>(j)<<" "<<dynamic_cast<integerAttribute*>(get<2>(j))->getval()<<endl;
                }
            }
            Relation *R4 = Rselection(tables[a1 - 1], &f);           
            R4->display_table();
            tables.push_back(R4);
            ntables++;
            home();
            break;
           }

        case 6:
           {
            cout << "Enter the input table no. whose Attribute Name is to be renamed: " << endl;
            view();
            int a;
            cin >> a;
            cout<<"Attribute Names: ";
            for(auto name: tables[a-1]->getattrnames()){
                cout<<name<<" ,";
            }
            cout << "Enter the existing attribute name(from the Above shown List): ";
            string s1, s2;
            cin >> s1;
            cout << "Enter the new attribute name: ";
            cin >> s2;
            tables[a - 1]=Rename(tables[a - 1], s1, s2);
            tables[a - 1]->display_table();
            home();
            break;
           }
        case 7:
           {
            cout << "Enter the table nos. of whose natural join is to be generated" << endl;
            cin >> a >> b;
            Relation *R5 = NaturalJoin(tables[a - 1], tables[b - 1]);
            R5->display_table();
            tables.push_back(R5);
            ntables++;
            home();
            break;
           }

        case 8:
            home();
        default:
            home();
        }
    }
};

int main()
{
    cout<<"Relation Interpreter built from Scrap....."<<endl;
    cout<<endl;
    interface a;
    a.home();
    return 0;
}
