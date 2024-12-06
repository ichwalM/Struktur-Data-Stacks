#include <iostream>
#include <string>
using namespace std;
#define MAX_STACK 1000

struct Stack{
    string elemen[MAX_STACK];
    int top;
};
void createStack(Stack &stack){
    stack.top = -1;
}
bool isEmpty(Stack stack){
    return stack.top == -1;
};
bool isFull(Stack stack){
    return stack.top == MAX_STACK - 1;
}
void push(Stack &stack, string i) {
    if (isFull(stack)){
        cout << "Stack overflow" << endl;
        return;
    }
    stack.top++;
    stack.elemen[stack.top] = i;
}
void pop(Stack &stack, string &i){
    if (isEmpty(stack)) {
        cout << "Stack underflow" << endl;
        return;
    }
    i = stack.elemen[stack.top];
    stack.top--;
}
void display(Stack stack) {
  if (isEmpty(stack)) {
    cout << "Stack kosong" << endl;
    return;
  }
  cout << "Isi dari Stack : ";
  for (int i = stack.top; i >= 0; i--) {
    cout << stack.elemen[i]<<" ";
  }
}
void clearStack(Stack &stack) {
    stack.top = -1;
}
void ui();
int main(){
    Stack stc;
    createStack(stc);
    int choice;
    string n;
    while(true){
        system("clear");
        ui();cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:{
                system("clear");
                cout<<"Masukkan Data yang akan dimasukkan: ";getline(cin,n);
                push(stc, n);
                cout<<"Data "<<n<<" telah ditambahkan..."<<endl<<endl;
                system("sleep 1.5");
                break;
            }
            case 2:{
                system("clear");
                pop(stc,n);
                cout<<"Data "<<n<<" Berhasil di Pop..."<<endl<<endl;
                system("sleep 1.5");
                break;
            }
            case 3:{
                system("clear");
                display(stc);
                cout<<endl;
                system("sleep 1.5");
                break;
            }
             case 4:{
                system("clear");
                clearStack(stc);
                cout<<"Stack berhasil di kosongkan"<<endl;
                system("sleep 1.5");
                break;
            }
            case 5:
                return 0;
        }
    }
}

void ui(){
    cout << "Implementasi Struct pada Array" << endl;
    cout << "==============================" << endl << endl;
    cout << "Menu:" << endl;
    cout << "1. Push Data" << endl;
    cout << "2. Pop Data" << endl;
    cout << "3. Tampilkan Stack" << endl;
    cout << "4. Kosongkan Stack" << endl;
    cout << "5. Keluar" << endl;
    cout<<"Masukkan pilihan[1..5] : ";
}
