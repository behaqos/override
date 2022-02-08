int main(void){
    char username[96];
    char password_file[40];
    char password[96];
    bzero(username, 96);
    bzero(password_file, 40);
    bzero(password, 96);
    FILE *fd = fopen("/home/users/level03/.pass", "r");
    if (!fd){
        fwrite("ERROR: failed to open password file\n", 0x1, 0x24, stderr);
        exit(1);
    }
    int res = fread(password_file, 0x1, 41, fd);
    int n = strcsnpn(password_file, "\n");
    password_file[n] = '\0';
    if (res != 41){
        fwrite("ERROR: failed to read password file\n", 0x1, 0x24, stderr);
        fwrite("ERROR: failed to read password file\n", 0x1, 0x24, stderr);
        exit(1);
    }
    //Line <+361>
    fclose(fd);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |")
    puts("\\**************************************/");
    //Line <+413>
    printf("--[ Username: ");
    fgets(username, 100, stdin);
    n = strcsnpn(username, "\n");
    username[n] = '\0';
    printf("--[ Password: ");
    fgets(password, 100, stdin);
    n = strcsnpn(password, "\n");
    password[n] = '\0';
    puts("\\**************************************/");
    if(strncmp(password_file, password, 41) != 0){
        printf(username);
        puts(" does not have access!");
        exit(1);
    }
    printf("Greetings, %s!\n", username);
    system("/bin/sh");
    return 0;
}