#include "locker.h"
 
void init(Lock *lock) {
    lock->status = 0; // unlocked
    return;
}
 
int lock(Lock *lock, int combination) {
    if(lock->status == 1)
        return -1;
 
    if(combination >= 0 && combination <= 9999) {
        lock->combo = combination;
        lock->status = 1;
        return combination;
    }
    return 10000;
}
 
int unlock(Lock *lock, int combination) {
    if(lock->status == 0)
        return -1;
    if(lock->combo == combination) {
        lock->status = 0;
        return 0;
    }
    return 1;
}
 
int isLocked(Lock *lock) {
    return lock->status;
}
