#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>

static struct pam_conv conv = {
    misc_conv,
    NULL
};

int main(int argc, char *argv[])
{
   
    const char *user;

    if(argc == 2) {
	user = argv[1];
    }

    if(argc > 2) {
	fprintf(stderr, "Usage: check_user [username]\n");
	exit(1);
    }
    if (argc < 2 ) { 
	printf("User is not chosen!\n");
    }
    int retval;
    pam_handle_t *pamh=NULL;
   

    retval = pam_start("check", user, &conv, &pamh);

    if (retval == PAM_SUCCESS){
        retval = pam_authenticate(pamh, 0);
	if (retval != PAM_SUCCESS)
		printf("pam_auth error: %s\n", pam_strerror(pamh, retval));
    }

    if (retval == PAM_SUCCESS){
        retval = pam_acct_mgmt(pamh, 0);
	if (retval != PAM_SUCCESS)
    	 	printf("pam_acct_mgmt error: %s\n", pam_strerror(pamh, retval));
	}


    if (retval == PAM_SUCCESS) {
	fprintf(stdout, "Authenticated\n");
    } else {
	fprintf(stdout, "Not Authenticated\n");
    }

    if (pam_end(pamh,retval) != PAM_SUCCESS) {
	pamh = NULL;
	fprintf(stderr, "check_user: failed to release authenticator\n");
	exit(1);
    }
    return ( retval == PAM_SUCCESS ? 0:1 );
}

