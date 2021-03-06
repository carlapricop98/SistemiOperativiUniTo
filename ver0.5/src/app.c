#include "include/inc.h"

int main(){

    int key;
    int shmid;
    int c;
    cell (*shmAt)[W];
    char* fileConf = "../conf/conf.csv";
    char* ch[4];
    char* nTaxi = (char*)malloc(16*sizeof(char));
    char* timeout = (char*)malloc(16*sizeof(char));
    conf* confg;
    pid_t figli[2];
    struct sigaction sa;


    /** TEST **/

    /** END TEST **/

    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = ccHandler;
    sigaction(SIGINT, &sa, NULL);

    confg = (conf*) malloc(sizeof(conf));
    key = ftok(".", 'b');
    createKeyFile(key);
    printf("DEBUG: Verifica Chiave: %d\n", readKey());
    parseConf(confg, fileConf);
    printConf(confg);
    shmid = createshm();
    shmAt = shmat(shmid, NULL, 0);
    fillConf(confg);
    holesHandler(confg->soHoles);
    printMtx();

    sprintf(nTaxi, "%d", confg->soTaxi);
    sprintf(timeout, "%d", confg->soTimeOut);

    ch[0] = "./exe/taxiH";
    ch[1] = nTaxi;
    ch[2] = timeout;
    ch[3] = NULL;

    if((figli[0]=fork()) == -1){

        perror("\nDEBUG: FORK ANDATO MALE\n");
        shmdt(shmAt);
        deleteshm();
        free(timeout);
        free(nTaxi);
        free(confg);
        exit(EXIT_FAILURE);

    }else if(figli[0] == 0){
        execvp(ch[0], ch);
    }

    for(c=0; c<1; c++)
        waitpid(WAIT_ANY, NULL, 0);

    printf("\nDEBUG: Morto TaxiHandler\n");

    shmdt(shmAt);
    deleteshm();;
    free(confg);
    free(timeout);
    free(nTaxi);
    return 0;

}

