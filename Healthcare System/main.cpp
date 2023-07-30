#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;
struct cl_patient
{
char first_name[20];
char last_name[20];
char patient_add[200];
char patient_phonenumber[10];
int patient_age;
char patient_gender[8];
char patient_bloodtype[5];
char patient_disease_pt[50];
int patient_id;
char patient_symptom[500];
char patient_disease[500];
char patient_disability[500];
char patient_addmission[30];
struct cl_patient *next;
bool disease_patient;
bool systolic, diastolic;
};
struct cl_patient *header,*last_partner;
bool checking=true;
int array[20]={0},v=0;
bool check_id(int ch)
{
for(int y=0;y<v;y++)
{
if(ch==array[y])
{
return true;
}
}
return false;
};
class Doctor
{
public:
void DataBase(struct cl_patient*);
void add_data()
{
fstream file("DataBase.csv",std::ios::app);
cl_patient *pat;
pat=new cl_patient;
pat->disease_patient=false;
cout<<"Enter Patient ID"<<endl;
cin>>pat->patient_id;
cout<<"Enter Patient First Name"<<endl;
cin>>pat->first_name;
cout<<"Enter Patient Last name"<<endl;
cin>>pat->last_name;
cout<<"Enter Patient Age"<<endl;
cin>>pat->patient_age;
cout<<"Enter Patient Gender"<<endl;
cin>>pat->patient_gender;
cout<<"Enter Patient Blood Group"<<endl;
cin>>pat->patient_bloodtype;
cout<<"Enter Patient Contact "<<endl;
cin>>pat->patient_phonenumber;
cin.ignore();
cout<<"Enter Patient Address"<<endl;
cin.getline(pat->patient_add,1000);
pat->next=NULL;
array[v]=pat->patient_id;
DataBase(pat);
v++;
if(checking)
{
header=pat;
last_partner=pat;
checking=false;
}
else
{
last_partner->next=pat;
last_partner=pat;
}
}
void show_data()
{
int z;
cl_patient *cur=NULL,*previous=NULL;
previous=header;
cur=header;
int change;
cout<<"Enter Patient ID"<<endl;
cin>>change;
if(check_id(change))
{
while(cur->patient_id!=change)
{
    previous=cur;
cur=cur->next;
}
cout<<"Enter Patient First Name"<<endl;
cout<<cur->first_name<<endl;
cout<<"Enter Patient Last Name"<<endl;
cout<<cur->last_name<<endl;
cout<<"Enter Patient ID"<<endl;
cout<<cur->patient_id<<endl;
cout<<"Enter Patient Age"<<endl;
cout<<cur->patient_age<<endl;
cout<<"Enter Patient Gender"<<endl;
cout<<cur->patient_gender<<endl;
cout<<"Enter Patient Blood Type"<<endl;
cout<<cur->patient_bloodtype<<endl;
cout<<"Enter Patient Contact "<<endl;
cout<<cur->patient_phonenumber<<endl;
cout<<"Enter Patient Address"<<endl;
cout<<cur->patient_add<<endl;
cout<<"*"<<endl;
if(cur->disease_patient){
cout<<"Enter Symptoms"<<endl;
cout<<cur->patient_symptom<<endl;
cout<<"Enter any previous major disease"<<endl;
cout<<cur->patient_disease<<endl;
cout<<"Does the patient have disabilities? Enter Yes/No"<<endl;
cout<<cur->patient_disability<<endl;
cout<<"Admit Required to Hospital?"<<endl;
cout<<cur->patient_addmission<<endl;
}}
else
{
cout<<"ID not present"<<endl;
}
}
void diagnosis()
{
int z;
cl_patient *pat=NULL,*previous=NULL;
pat=new cl_patient;
previous=header;
pat=header;
int change;
cout<<"Enter Patient ID"<<endl;
cin>>change;
if(check_id(change)){
while(pat->patient_id!=change )
{
previous=pat;
pat=pat->next;
}
pat->disease_patient=true;
cout<<"Enter Symptoms"<<endl;
cin>>pat->patient_symptom;
cout<<"Enter any previous major disease "<<endl;
cin>>pat->patient_disease;
cout<<"Does the patient have disabilities? Enter Yes/No"<<endl;
cin>>pat->patient_disability;
cout<<"Admit Required to Hospital?"<<endl;
cin>>pat->patient_addmission;
}
else
cout<<"ID is not Registered\n";
}
void update_menu()
{
cout<<"Enter 1 Patient First Name"<<endl;
cout<<"Enter 2 Patient Last Name"<<endl;
cout<<"Enter 3 Patient ID"<<endl;
cout<<"Enter 4 Patient Age"<<endl;
cout<<"Enter 5 Patient Gender"<<endl;
cout<<"Enter 6 Patient Blood Type"<<endl;
cout<<"Enter 7 Patient Phone Number "<<endl;
cout<<"Enter 9 Patient Address"<<endl;
cout<<"*"<<endl;
cout<<"Enter 10 Symptoms"<<endl;
cout<<"Enter 11 Enter any previous major disease"<<endl;
cout<<"Enter 12 Does the patient have disabilities? Enter Yes/No"<<endl;
cout<<"Admit 13 Required to Hospital?"<<endl;
}
void update_data(){
cl_patient *cur=NULL,*previous=NULL;
cur=header;
previous=header;
int patient_id,change;
cout<<"Enter ID"<<endl;
cin>>patient_id;
if(check_id(patient_id)){
while(cur->patient_id!=patient_id)
{
previous=cur;
cur=cur->next;
}
update_menu();
cout<<"Choose Number"<<endl;
cin>>change;
if(change==1){
cout<<"Enter First Name"<<endl;
cin>>cur->first_name;
}
else if(change==2){
cout<<"Enter Second Name"<<endl;
cin>>cur->last_name;
}
else if(change==3){
cout<<"Enter ID"<<endl;
cin>>cur->patient_id;
}
else if(change==4){
cout<<"Enter Age"<<endl;
cin>>cur->patient_age;
}
else if(change==5){
cout<<"Enter Gender"<<endl;
cin>>cur->patient_gender;
}
else if(change==6){
    cout<<"Enter Blood Type"<<endl;
cin>>cur->patient_bloodtype;
}
else if(change==7){
cout<<"Enter Phone Number"<<endl;
cin>>cur->patient_phonenumber;
}
else if(change==9){
cout<<"Enter Address"<<endl;
cin>>cur->patient_add;
}
else if(change==10){
cout<<"Enter 10 Symptoms"<<endl;
cin>>cur->patient_symptom;
}
else if(change==11){
cout<<"Enter 11 Enter any previous major disease"<<endl;
cin>>cur->patient_disease;
}
else if(change==12){
cout<<"Enter 12 Does the patient have disabilities? Enter Yes/No"<<endl;
cin>>cur->patient_disability;
}
else if(change==13){
cout<<"Admit 13 Required to Hospital?"<<endl;
cin>>cur->patient_addmission;
}
}
else
cout<<"ID not present"<<endl;
}
void sugar_analysis()
{
float sugar_level;
std::cout << "[+]Enter your sugar level : " << std::endl;
cin.ignore();
std::cin >> sugar_level;
if(sugar_level > 70 && sugar_level < 99)
{
std::cout << "You may be diabitic.. Start your diet" <<
std::endl;
}
if(sugar_level > 99 && sugar_level < 400)
{
std::cout << "High sugar, Take your meds" << std::endl;
}else{
std::cout << "Invalid range of sugar level" << std::endl;
}
}
void bloodPressure_analysis()
{
float bloodPressure;
std::cout << "[+]Enter your blood pressure range : ";
std::cin >> bloodPressure;
if(bloodPressure < 120)
{
std::cout << "Your blood pressure is normal " << std::endl;
}else if(bloodPressure >= 120 && bloodPressure < 129)
{
std::cout << "Your blood pressure is ELEVATED, get some rest!" <<
std::endl;
}else if(bloodPressure >= 130 && bloodPressure <= 139)
{
std::cout << "Your blood pressure is HIGH , get Hospitilized" <<
std::endl;
}
else{
std::cout << "Invalid range" << std::endl;
}
}
};
void Doctor::DataBase(struct cl_patient* pat)
{
std::fstream file("DataBase.csv",ios::app);
file << pat->patient_id <<","
<< pat->first_name << ","
<< pat->last_name << ","
<< pat->patient_gender << ","
<< pat->patient_bloodtype << ","
<< pat->patient_phonenumber << ","
<< pat->patient_add
<< std::endl;
}
void display_menu()
{
cout<<"|=================================|"<<endl;
cout<<"|[1] Add New Patient Record |"<<endl;
cout<<"|[2] Add Patient Prescription |"<<endl;
cout<<"|[3] Full History of the Patient |"<<endl;
cout<<"|[4] Update Patient Record |"<<endl;
cout<<"|[5] Diagnose Sugar Levels |"<<endl;
cout<<"|[6] Diagnose Blood Pressure |"<<endl;
cout<<"|[7] Add to data base record |"<<endl;
cout<<"|[8] EXIT |"<<endl;
cout<<"|=================================|"<<endl;
cout<<"Enter the number you want to Choose:"<<endl;
}
void menu()
{
cout<<"press 1 To Doctor Menu"<<endl;
cout<<"press 2 To Patients Menu"<<endl;
cout<<"press 3 To Pharmacist Menu"<<endl;
}
int main()
{
struct cl_patient* header=NULL;
Doctor m;
int v=0;
do{
display_menu();
cin>>v;
if(v==1)
m.add_data();
else if(v==2)
m.diagnosis();
else if(v==3)
m.show_data();
else if(v==4)
m.update_data();
else if(v==5)
m.sugar_analysis();
else if(v==6)
m.bloodPressure_analysis();
else if(v==7)
// Dummy Function add here
std::cout<<std::endl;
else if(v==8)
exit(0);
}while(1);
return 0;
}