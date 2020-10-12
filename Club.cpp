#include "Club.h"

void Club::chargeDelay(int nif, int account,Book book){
    bool ismember;
    float fine=book.getValue()*0.10;
    for(unsigned i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            account-=fine;
            ismember=true;
        }
    }
    if(ismember==false){
        account-=(fine*2);
    }
}

void Club::chargeFee(int nif, int account,Book book){
    bool ismember;
    float fee=book.getValue()*0.05;
    for(unsigned i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            ismember=true;
        }
    }
    if(ismember==false){
        account-=fee;
    }
}
