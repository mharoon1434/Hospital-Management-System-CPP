#include<iostream>
#include<vector>
#include<string>
#include<fstream>
       using namespace std;
int main();
int Exit();
class Patient;
class Person{
	public:
		string name;
		int age;
		string gender;
		string contactNumber;
		Person(string name, int ag,string gen,string contactno){
			this->name=name;
			age=ag;
			gender=gen;
			contactNumber=contactno;
		}
		Person(){
		}
		string getname(){
			return name;
		}
		int getAge(){
			return age;
		}
		string getGender(){
			return gender;
		}
};
class Admin:public Person{
	public:
		double Password;
		Admin(string na,int ag,string gen,string contactno,double pasword):Person(na,ag,gen,contactno){
			Password=pasword;
		}
		bool checkInfo(string na,double pword){
			if(name==na&&Password==pword){
				return true;
			}
			return false;
		}
		friend void printinfo(vector <Admin>& D){
		system("cls");
    	cout<<"Name \t| Age \t| Contact\n";
    	for(int i=0; i<D.size(); i++){
    		cout<<D[i].name<<"\t| "<<D[i].age<<" \t| "<<D[i].contactNumber<<"\n";
		}
	}
	Admin(){
	}
};
class Employees:public Person{
	public:
		string workingDay;
	Employees(string na, int ag, string gender, string contactno, string wDay):Person(na,ag,gender,contactno){
		workingDay=wDay;
	}
	Employees(){
	}
	string getname(){
    	return name;
	}
	string getworkingday(){
		return workingDay;
	}
};
class Doctor:public Employees {
	public:
		string specilization;
	Doctor(string na, int ag, string gender,string contactno,string sp, string workday):Employees(na,ag,gender,contactno, workday){
		specilization=sp;
	}
	Doctor(){
	}
	void display(){
		cout<<name<<"\t\t|\t"<<specilization<<"\t|\t"<<workingDay<<"\n";
	}
    friend void printinfo(vector <Doctor>& D){
    	system("cls");
    	cout<<"Name\t|\tAge | Contact\t|\tSpecification\t|\tWorkingDay\n";
    	for(int i=0; i<D.size(); i++){
    		cout<<D[i].name<<"\t| "<<D[i].age<<" | "<<D[i].contactNumber<<"\t| "<<D[i].specilization<<"\t|\t"<<D[i].workingDay<<"\n";
		}
	}
	static int findRelatedDoctor(vector <Doctor> D){
		int choice;
		for(int i=0; i<D.size(); i++){
			cout<<i+1<<". "<<D[i].getname()<<"\t\t | \tDuty Day "<<"\t->\t"<<D[i].getworkingday()<<"\t|\t"<<D[i].specilization;
			cout<<endl;
		}
		cout<<endl;
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;
	}
	void  availability(string day, vector <Doctor>& D){
		vector <Doctor> duty;
		int checker=0;
		for(int i=0; i<D.size(); i++){
		          int k=0;
			for(int j=0; j<D[i].workingDay.size(); j++){
			 if(day[k]==D[i].workingDay[j]){
			 	checker++;
			 	k++;
			 }else{
			 	k=0;
			 	checker=0;
			 }
			 if(checker==3){
			 D[i].display();
			 checker=0;	
		}
		}
		 


}
}
}; 
class Nurse:public Employees{
	public:
		int id;
	Nurse(string na, int ag, string gender,string contactno,int i, string workday):Employees(na,ag,gender,contactno, workday){
		id=i;
	}
	static int findRelatedNurse(vector <Nurse>& D){
		int choice;
		for(int i=0; i<D.size(); i++){
			cout<<i+1<<". "<<D[i].getname()<<"\t\t | \tDuty Day "<<"\t->\t"<<D[i].getworkingday();
			cout<<endl;
		}
		cin.ignore();
		cout<<endl;
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;
	}
	friend void printinfo(vector <Nurse>& D){
		system("cls");
    	cout<<"Name\t\t|id\t|Age\t | Contact\t\t| WorkingDay\n";
    	for(int i=0; i<D.size(); i++){
    		cout<<D[i].name<<"\t| "<<D[i].id<<" | "<<D[i].age<<"\t| "<<D[i].contactNumber<<"\t| "<<D[i].workingDay<<"\n";
		}
	}
	Nurse(){
	}
};
class Patient:public Person{
	public:
	string assignDoctor;
	int isadmitt=0;
	static	int sr;
	bool paid=false;
	double normalfee=1200;
	Patient(string name, int ag, string gender, string contactno, string aDoctor):Person(name,ag,gender,contactno){
		assignDoctor=aDoctor;
		sr++;
	}
	void paidamount(){
		cout<<"Pay Successfully -> "<<normalfee<<"\n";
		paid=true;
	}
	    bool ispaid(){
		return paid;
	}
	Patient(){
	}
	friend void printInfo(vector <Patient>& p){
	system("cls");
    cout<<"Name\t|\tAge\t|\tGender\t|\tDoctor\n";
    for(int i=0; i<p.size(); i++){
    	cout<<p[i].name<<"\t|\t"<<p[i].age<<"\t|\t"<<p[i].gender<<"\t|\t"<<p[i].assignDoctor<<endl;
	}
		
	}
	Patient newpatient(vector <Patient>& P , vector <Doctor>& D)
	{
		system("cls");
		string name;
		int age;
		string gender;
		string contactNumber;
		string assingD;
		cout<<"Name of patients  ";
		cin.ignore();
		getline(cin,name);
		cout<<"Age of patients  ";
	    cin>>age;
	    cout<<"Gender (male or female)  ";
	    cin.ignore();
		cin>>gender;
		cout<<"ContactInfo of patients  ";
		cin.ignore();
		getline(cin,contactNumber);	
		int cond;
		cout<<"Is Patients are in Emergency condition\n";
		cout<<"1. if normal\n2. if Emergency condition\n\n";
		cout<<"\nWhat you Want?  :  ";
		cin>>cond;
		if(cond==1){
			int choice;
			cout<<"Assign Doctor to Patients\n";
			cout<<"0. if the related Doctor are not Available\n";
			int index=D[0].findRelatedDoctor(D);
		    cin.ignore();
		    if(cond==0){
		    	main();
			}
			else if(index){
			int ischeck=0;
			for(int i=0; i<D.size(); i++){
				if(i+1==index){
				assingD=D[index-1].name;
		    	Patient P1(name, age,gender,contactNumber,assingD);
				P.push_back(P1);
				savePatientDetais(P,"Patients Data.txt");
				savePatientDetaisforRetrive(P, "Patients Retrive.txt");
				ischeck==1;
				
				return P1;		
				}	
			}
			if(ischeck==0){
					cout<<"Does not correct index\n";	
				}
	    	}
		    else if(cond==2){
			assingD="Not Define";
	    	Patient P1(name, age,gender,contactNumber,assingD);
	    	P.push_back(P1);
			savePatientDetais(P,"Patients Data.txt");
			savePatientDetaisforRetrive(P, "Patients Retrive.txt");
			return P1;
	 	}
	 	else{
	  		cout<<"X Choices\n";
		  }
		  
	}
	Patient P2;
	return P2;
}
	int addpatient(vector <Patient>& P, vector <Doctor>& D){
	    newpatient(P,D);
		int ch;
		system("cls");
		cout<<"Patients Add Successfully\n";
		cout<<"Select the further operation\n";
	    cout<<"1 Main\n2. Add one more Patients\n\n";
	   cout<<"\nWhat you Want?  :  ";
	    cin>>ch;
	    if(ch==1){
	    	main();
		}
		if(ch==2){
		addpatient(P,D);	
		}
		return 0;
	}
	int patientOpition(vector <Patient>& P){
		int choice;
		bool isallAdmit=true;
		for(int i=0; i<P.size(); i++){
			if(!P[i].isadmitt){
				isallAdmit=false;
				cout<<i+1<<". "<<P[i].name<<" having age "<<P[i].age<<" ContactNumber -> "<<P[i].contactNumber<<"\t"<<isadmitt<<"\n";
			}
			
			
		}
		if(isallAdmit==true||P.size()==0){
			cout<<"No Patient in record\n";
			Exit();
		}
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;
	}
	void printPaidPatientDetalis(vector <Patient>& P){
		bool isallpad=true;
		for(int i=0; i<P.size(); i++){
			if(P[i].paid==true){
				if(isallpad){
					cout<<"Name\t\t|\tFee\n";
				}
				isallpad==false;
				cout<<P[i].name<<"\t\t|\t"<<P[i].normalfee<<endl;
			}
		}
		if(isallpad){
			cout<<"Does not Paid any Patients\n";
		}
		
	}
	vector <Patient> printUnPaidPatientDetalis(vector <Patient>& P){
		bool isallpad=true;
		vector <Patient> Unpaid;
		for(int i=0; i<P.size(); i++){
			cout<<"is paid "<<P[i].paid<<endl;
			if(P[i].paid==false){
				if(isallpad){
					cout<<"Name\t\t|\tFee\n";
					isallpad==false;
				}
				else{
					cout<<"x choice\n";
				}
				cout<<P[i].name<<"\t\t|\t"<<P[i].normalfee<<endl;
				Unpaid.push_back(P[i]);
				isallpad==false;
			}
		}
		if(isallpad){
			cout<<"All Patients are paid\n";
		}
	return Unpaid;	
	}
		int patientmanu(vector <Patient> P){
		int choice;
		cout<<"select relative opition\n";
		for(int i=0; i<P.size(); i++){
			cout<<i+1<<". patient name "<<P[i].name<<" amount pay "<<P[i].normalfee<<"\n";
		}
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;
		
	}
	   int	mainuforDischargepatient(vector <Patient>& P){
        int choice;
		cout<<"select relative opition\n";
		for(int i=0; i<P.size(); i++){
			cout<<i+1<<". for patient "<<P[i].name<<" age "<<P[i].age<<"\n";
		}
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;
			
	}
		void discharge(vector <Patient>& Ad, int index){
		if(!Ad[index-1].paid){
					int op;
		   			cout<<"Does not pay Hospital Bails of Rs. "<<	Ad[index-1].normalfee<<"\n";
					cout<<"1. paid  ";
					cin>>op;
					Ad[index-1].paidamount();
					cout<<"Patients Dischage successfully\n";
				}
		else{
			cout<<"Patients Already Pay Hospital Balis and ready to Dischage\n";
			cout<<"Patients Dischage successfully\n";
		}
		
	}
	friend void savePatientDetais( vector<Patient> Patients,  string filename);
    friend void savePatientDetaisforRetrive( vector<Patient> Patients,  string filename);
};
int Patient::sr=0;
class AdmittPatients:public Patient{
	public:
		string admissionDate;
		string dischargeDate;
		int roomNumber;
		int numberofday;
		double feeParday=2000;
		string assignNurse;
		double normalf;
	AdmittPatients(string na, int ag, string gender, string contactno ,string aDate,string dDate, int room, string aNurse, string doctorname):Patient(na,ag,gender,contactno,doctorname){
	    admissionDate=aDate;
	    dischargeDate=dDate;
	    roomNumber=room;
    	assignNurse=aNurse;
    	isadmitt=1;
    	int seconddate=stoi(dischargeDate);
		int firstdate=stoi(admissionDate);
    	if(firstdate>seconddate){
    	         	firstdate=30-firstdate;
					numberofday=seconddate+firstdate;
				}else{
					numberofday=seconddate-firstdate;
				}
				normalf=1200+numberofday*2000;
}
    AdmittPatients(){
	}
	void paidamount(){
		cout<<"Pay Successfully -> "<<normalf<<"\n";
		paid=true;
	}
int addpatients(Patient p1,vector <AdmittPatients>& Ap, vector <Doctor>& D,vector <Nurse>& N, vector <Patient>& P){
	            string admissionDate;
		        string dischargeDate;
	        	int roomNumber;
	        	string assignNurse;
				cout<<"Admitt Date (ignor Month and years)  ";
				cin>>admissionDate;
				cout<<"Expected Discharge Date (ignor Month and years)  ";
				cin>>dischargeDate;
				cout<<"RoomNumber  ";
				cin>>roomNumber;
				int numberofday;
				cout<<"Assign Nurse for the Care of Patients  ";
				int index=N[0].findRelatedNurse(N);
				int iscorrect=1;	
				for(int i=0; i<D.size(); i++){
				if(i+1==index){
				assignNurse=N[index-1].name;					
			AdmittPatients p2(p1.name,p1.age,p1.gender,p1.contactNumber,admissionDate,dischargeDate,roomNumber, assignNurse, p1.assignDoctor);
				p2.isadmitt=1;
				Ap.push_back(p2);
				savePatientDetais(Ap,"Addmat Patients Data.txt");
		    	savePatientDetaisforRetrive(Ap, "AddmatPatients Retrive.txt");
				iscorrect=0;
			}
		       
		}
		    if(iscorrect){
		    cout<<"Not a correct opition\n";
			   }
			int ch;
		    cout<<"Patients Addmit Successfully\n\n";
	     	cout<<"Select the further operation\n";
	        cout<<"1. Main\n2. Add one more Patients\n";
	        cout<<"\nWhat you Want?  :  ";
	        cin>>ch;
	           if(ch==1){
	            	main();
	    	}
	        	if(ch==2){
	        	admitpatients(Ap,P,D,N);	
      		}
      		return 0;
}
	int admitpatients(vector <AdmittPatients>& Ap ,vector <Patient>& P ,vector <Doctor>& D, vector <Nurse>& N){
		system("cls");
		int count;
		cout<<"Select the condition of patient\n";
		cout<<"1. new coming patient\n";
		cout<<"2. existing Patient\n";
		cout<<"\nWhat you Want?  :  ";
		cin>>count;
		switch(count){
			case 1:{
				Patient p1=newpatient(P,D);
				addpatients(p1,Ap,D,N,P);
      		break;
	}
	case 2:{
		int index=P[0].patientOpition(P);
		Patient p1=P[index-1];
		addpatients(p1,Ap,D,N,P);
		
		break;
	}
	}
	return 0;
}
	friend void printInfo(vector <AdmittPatients>& p){
	system("cls");
    cout<<"Name\t|\tAge\t|\tDisCharge Date\t|\tDoctor\t|\tNurse\n";
    for(int i=0; i<p.size(); i++){
    	cout<<p[i].name<<"\t|\t"<<p[i].age<<"\t|\t"<<p[i].dischargeDate<<"\t\t|\t"<<p[i].assignDoctor<<"\t|\t"<<p[i].assignNurse<<endl;
	}	
	}
   	void printPaidPatientDetalis(vector <AdmittPatients>& P){
		bool isallpad=true;
		for(int i=0; i<P.size(); i++){
			if(P[i].paid==true){
				if(isallpad){
					cout<<"Name\t\t|\tFee\n";
				}
				isallpad==false;
				cout<<P[i].name<<"\t\t|\t"<<P[i].normalf<<endl;
			}
		}
		if(isallpad){
			cout<<"Does not Paid any Patients\n";
		}
	}
	vector <AdmittPatients> printUnPaidPatientDetalis(vector <AdmittPatients>& P){
		bool isallpad=true;
		vector <AdmittPatients> Unpaid;
		for(int i=0; i<P.size(); i++){
			cout<<"is paid "<<P[i].paid<<endl;
			if(P[i].paid==false){
				if(isallpad){
					cout<<"Name\t\t|\tFee\n";
					isallpad==false;
				}
				else{
					cout<<"x choice\n";
				}
				cout<<P[i].name<<"\t\t|\t"<<P[i].normalf<<endl;
				Unpaid.push_back(P[i]);
				isallpad==false;
			}
		}
		if(isallpad){
			cout<<"All Patients are paid\n";
		}
	return Unpaid;	
	}
		int patientmanu(vector <AdmittPatients> P){
		int choice;
		cout<<"select relative opition\n";
		for(int i=0; i<P.size(); i++){
			cout<<i+1<<". patient "<<P[i].name<<" amount pay "<<P[i].normalf<<"\n";
		}
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;	
	}
    int	mainuforDischargepatient(vector <AdmittPatients> P){
        int choice;
		cout<<"select relative opition\n";
		for(int i=0; i<P.size(); i++){
			cout<<i+1<<". patient "<<P[i].name<<" age "<<P[i].age<<"\n";
		}
		cout<<"\nWhat you Want?  :  ";
		cin>>choice;
		return choice;	
	}
	void discharge(vector <AdmittPatients>& Ad, int index){
		cout<<"The discharge date of "<<Ad[index-1].name<<" is "<<Ad[index-1].dischargeDate<<"\n";
		string date;
		cout<<"Data of Dischage  ";
		cin>>date;
		int seconddate=stoi(Ad[index-1].dischargeDate);
	   	int firstdate=stoi(Ad[index-1].admissionDate);
		int dateint=stoi(date);
		if(!Ad[index-1].paid){
			if(seconddate>dateint){
				int lessday=seconddate-dateint;
				seconddate=seconddate-lessday;
            	if(firstdate>seconddate){
    	         	firstdate=30-firstdate;
					Ad[index-1].numberofday=seconddate+firstdate;
				}else{
					Ad[index-1].numberofday=seconddate-firstdate;
						int op;
		   			 cout<<"Does not pay Hospital Bails of Rs. "<<	Ad[index-1].normalf<<"\n";
					cout<<"1. paid  ";			
					cin>>op;
					Ad[index-1].paidamount();
					cout<<"Patients Dischage successfully\n";
				}
			}
			else{
				Ad[index-1].normalf=1200+numberofday*2000;
				int op;
		        cout<<"Does not pay Hospital Bails of Rs. "<<normalf<<"\n";
			   cout<<"1. paid  ";
		    	cin>>op;
				Ad[index-1].paidamount();
				cout<<"Patients Dischage successfully\n";	
			}			
		}
		else{
			cout<<"Patients Already Pay Hospital Balis and Dischage\n";
			cout<<"Patients Dischage successfully\n";
		}
	}
	friend void savePatientDetais( vector<AdmittPatients> Patients,  string filename);
    friend void savePatientDetaisforRetrive( vector<AdmittPatients> Patients,  string filename);
    
};
void printMaiu(){
	cout<<"1. add normal patients\n2. admitt patients\n3. check availability of doctor\n4. informatiom of Stuff(Doctor, and Nurse)\n";
	cout<<"5. get payment\n6. Discharge admatt patient\n7. check the paid status of normal Patient and discharge theme\n8. print Patients list\n";
}
bool login(vector <Admin> A){
	static int islogin=0;
	if(islogin==1){
		return true;
	}else{
	    string name;
	    double password;
  	    cout<<"Login Information\n";
    	cout<<"Username  ";
    	cin>>name;
    	cout<<"Password  ";
    	cin>>password;
    	for(int i=0; i<A.size(); i++){
	    if(A[i].checkInfo(name,password)){
		islogin=1;
		return true;
	}	
	}
	}
	
	return 0;
}
int Exit(){
	int choice;
	cout<<"Choose the further operation\n";
	cout<<"1. main\n0. Exit\n";
	
	cout<<"\nWhat you Want?  :  ";
	cin>>choice;
	switch(choice){
		case 1:{
			main();
			break;
		}
		case 0:{
			return 0;
			break;
		}
		default:{
			cout<<"Does not correct opition\n";
			Exit();
			break;
		}
	}
	return 0;
}
vector<Admin> loadAdmin(string filename) {
    ifstream in(filename);
    Admin A;
    //retrieve Admin data of all objects
    vector<Admin> Admins;

    if (in) {
        string ageStr;
        string password;
        while (getline(in, A.name) && getline(in, ageStr)&&getline(in, A.gender)&& getline(in, A.contactNumber)&&getline(in,password)) {
            A.age = stoi(ageStr);
            A.Password=stod(password);
            Admins.push_back(A);
        }
    }
    in.close();
    return Admins;
}
vector<Doctor> loadDoctor(string filename) {
    ifstream in(filename);
    Doctor D;
    //retrieve data of all Doctor objects 
    vector<Doctor> Doctors;

    if (in) {
        string ageStr;
        while (getline(in, D.name) && getline(in, ageStr) && getline(in, D.gender) && getline(in, D.contactNumber) && getline(in,D.specilization) && getline(in,D.workingDay)) {
            D.age = stoi(ageStr);
            Doctors.push_back(D);
        }
    }
    in.close();
    return Doctors;
}
vector<Nurse> loadNurse(string filename) {
    ifstream in(filename);
    Nurse N;
    //retrieve Nata of all Nurse objects 
    vector<Nurse> Nurses;

    if (in) {
        string ageStr;
        string id;
        while (getline(in, N.name) && getline(in, ageStr) && getline(in, N.gender) && getline(in, N.contactNumber) && getline(in,id) && getline(in,N.workingDay)) {
            N.age = stoi(ageStr);
            N.id=stoi(id);
            Nurses.push_back(N);
        }
    }
    in.close();
    return Nurses;
}
vector <Patient> savepatientsRetrive(string filename){
	ifstream in(filename);
    Patient P;
    //retrieve Nata of all Patient objects 
    vector<Patient> Patients;

    if (in) {
        string ageStr;
        string id;
        while (getline(in, P.name) && getline(in, ageStr) && getline(in, P.gender) && getline(in, P.contactNumber) && getline(in,P.assignDoctor)) {
            P.age = stoi(ageStr);
            Patients.push_back(P);
        }
    }
    in.close();
    return Patients;
	
}
vector <AdmittPatients> saveadmitpatientsRetrive(string filename){
	ifstream in(filename);
    AdmittPatients AP;
    //retrieve Nata of all Admait Patient objects 
    vector<AdmittPatients> Patients;

    if (in) {
        string ageStr;
        string roomN;
        while (getline(in, AP.name) && getline(in, ageStr) && getline(in, AP.gender) && getline(in,AP.contactNumber) 
		&&getline(in,AP.admissionDate) && getline(in,AP.dischargeDate) && getline(in,roomN)&& getline(in, AP.assignNurse)&& getline(in,AP.assignDoctor)) {
            AP.age = stoi(ageStr);
            AP.roomNumber=stoi(roomN);
            Patients.push_back(AP);
        }
    }
    in.close();
    return Patients;
	
}
void savePatientDetais( vector<Patient> Patients,  string filename) {
    ofstream out(filename);
    if (out) {
    	out<<"Name\t|\tAge\t|\tGender\t|\tContact\t|\tDoctor\n";
        for (auto&  P: Patients) {
            out << P.name <<"\t|\t"<<P.age <<"\t|\t"<<P.gender<<"\t|\t"<<P.contactNumber<<"\t|\t"<<P.assignDoctor<<"\n";
        }
        out.close();
}
out.close();
}
void savePatientDetaisforRetrive( vector<Patient> Patients,  string filename) {
    ofstream out(filename);
    if (out) {
        for (auto&  P: Patients) {
            out << P.name <<"\n"<<P.age <<"\n"<<P.gender<<"\n"<<P.contactNumber<<"\n"<<P.assignDoctor<<"\n";
        }
        out.close();
}
}
//for addmat patients filehandling
void savePatientDetais( vector<AdmittPatients> Patients,  string filename) {
    ofstream out(filename);
    
    if (out) {
    	out<<"Name\t|\tAge |\t Gender |\tContact |\tAdimtDate |\t DischargeDate |\t RoomNO. |\tNurse\t|\tDoctor\n";
        for (auto&  P: Patients) {
            out << P.name <<"\t\t| "<<P.age <<"\t\t| "<<P.gender<<" \t|\t "<<P.contactNumber<<"\t|\t";
			out<<P.admissionDate<<"\t|\t "<<P.dischargeDate<<"\t|\t "<<P.roomNumber<<" \t|\t "<<P.assignNurse<<"  \t|\t "<<P.assignDoctor<<"\n";
        }
        out.close();
}
out.close();
}
void savePatientDetaisforRetrive( vector<AdmittPatients> Patients,  string filename) {
    ofstream out(filename);
    if (out) {
        for (auto&  P: Patients) {
            out << P.name <<"\n"<<P.age <<"\n"<<P.gender<<"\n"<<P.contactNumber<<"\n";
			out<<P.admissionDate<<"\n"<<P.dischargeDate<<"\n"<<P.roomNumber<<"\n"<<P.assignNurse<<"\n"<<P.assignDoctor<<"\n";
        }
        out.close();
}
out.close();
}
int main(){
	system("cls");
	cout<<"Hi Good Morning form HR Hospital\n\n";
	vector <Doctor> D=loadDoctor("Doctors.txt");
	static vector <Patient> P=savepatientsRetrive("Patients Retrive.txt");
	static vector <AdmittPatients> AP=saveadmitpatientsRetrive("AddmatPatients Retrive.txt");
	vector <Nurse> N=loadNurse("Nurses.txt");
	vector <Admin> A=loadAdmin("Admin.txt");
	if(login(A)){
	system("cls");
	cout<<"Wellcome As administrative of HR Hospital \n\n\n";
	int choice;
	printMaiu();
	cout<<"\nWhat you Want?  :  ";
	cin>>choice;
	switch(choice){
		case 1:{
			P[0].addpatient(P,D);
			break;
		}
		case 2:{
			AP[0].admitpatients(AP,P,D,N);
			break;
		}
		case 3:{
			string day;
			cout<<"First three letter of name of Day(Mon, Fri, Sun)\n";
		    cout<<"\nWhat you Want?  :  ";
			cin>>day;
			D[0].availability(day,D);
			Exit();
			break;
		}
		case 4:{
			int opition;
			cout<<"Where you go.......\n";
			cout<<"1. Doctor\n2. Nurse\n3. Admin\n";
			cout<<"\nWhat you Want?  :  ";
			cin>>opition;
			switch(opition){
				case 1:{
					printinfo(D);
					Exit();
					break;
				}
				case 2:{
					printinfo(N);
					Exit();
					break;
				}
				case 3:{
					printinfo(A);
					Exit();
					break;
				}
			}
			break;
		}
	    case 5:{
	    	int ch;
	    	cout<<"Select the type of patient\n";
	    	cout<<"1. for normal Patient\n2. Admatt Patient\n";
	    	cout<<"\nWhat you Want?  :  ";
	    	cin>>ch;
	    	switch(ch){
	    	      case 1:{
	    	      	int opition;
	    	      	cout<<"For Payment details\n";
	    	      	cout<<"1. Paid Patient\n2. unpaid Patient\n";
	    	      	cin>>opition;
	    	      	switch(opition){
	    	      		case 1:{
	    	      			P[0].printPaidPatientDetalis(P);
	    	      			Exit();
							break;
						  }
						case 2:{
							vector <Patient> unpaid=P[0].printUnPaidPatientDetalis(P);
							int opi;
							cout<<"1. receving payment form any Patient  ";
							cin>>opi;
							if(opi==1){
								int index=unpaid[0].patientmanu(unpaid);
								unpaid[index-1].paidamount();
								for(int i=0; i<P.size(); i++){
									if(P[i].name==unpaid[index-1].name&&P[i].contactNumber==unpaid[index-1].contactNumber){
										P[i].paid=true;
									}
								}
							}
							Exit();
							break;
						}
					  }
					break;
				  }
				  case 2:{
				  	int opition;
					cout<<"For Payment details\n";
	    	      	cout<<"1. Paid Patient\n2. unpaid Patient\n";
	    	      	cout<<"\nWhat you Want?  :  ";	
	    	      	cin>>opition;
	    	      	switch(opition){
	    	      		case 1:{
	    	      			AP[0].printPaidPatientDetalis(AP);
	    	      			Exit();
							break;
						  }
						case 2:{
							vector <AdmittPatients> unpaid=AP[0].printUnPaidPatientDetalis(AP);
							int opi;
							cout<<"1- for receving payment form any Patient  ";
							cin>>opi;
							if(opi==1){
								int index=unpaid[0].patientmanu(unpaid);
								unpaid[index-1].paidamount();
								for(int i=0; i<P.size(); i++){
									if(AP[i].name==unpaid[index-1].name && AP[i].contactNumber==unpaid[index-1].contactNumber){
										AP[i].paid=true;
									}
								}
							}
							Exit();
							break;
				  }
			}
			break;
		}
	}
}
		case 6:{
			if(AP.size()>=1){
			int index=AP[0].mainuforDischargepatient(AP);
			AP[index-1].discharge(AP , index);
			AP.erase(AP.begin()+index);
			savePatientDetais(AP,"Addmat Patients Data.txt");
		    savePatientDetaisforRetrive(AP, "AddmatPatients Retrive.txt");
			Exit();
			break;	
			}
			else{
				cout<<"No admatt Patient are exist\n";
			Exit();
			break;	
			}
			
		}
		case 7:{
			if(P.size()>=1){
			int index=P[0].mainuforDischargepatient(P);
			P[index-1].discharge(P , index);
			P.erase(P.begin()+index);
			savePatientDetais(P,"Patients Data.txt");
			savePatientDetaisforRetrive(P, "Patients Retrive.txt");
			Exit();
			break;
		}
		else{
			cout<<"No exist any Pateints\n";
			Exit();
			break;	
		}
	}
		case 8:{
			int k;
			cout<<"Select the type of patient to print list\n";
			cout<<"1- for Normal Patient\n";
			cout<<"2- for the admitt Patient\n";
			cout<<"\nWhat you Want?  :  ";	
			cin>>k;
			switch(k){
				case 1:{
					printInfo(P);
					Exit();
					break;
				}
				case 2:{
					printInfo(AP);
					Exit();
					break;
				}
			}
		}
	}
}
	else{
		cout<<"incorrect Information\n";
	}
	return 0;
}





