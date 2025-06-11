#include <stdio.h>
#include <string.h>

/* Some useful defines */
#define FILE_NUM	1
#define DEVICE_NUM	8
#define CHANNEL_NUM	2
#define FN_GAMEDATA "gamedata.dat"
#define STATUS_OK   0
#define STATUS_FAIL 1

#define REC_LOC_START	"loc"
#define REC_LOC_END		"endloc"
#define REC_OBJ_START	"obj"
#define REC_OBJ_END		"endobj"

#define SHORT_DESC_LEN  32
#define LONG_DESC_LEN   256
#define MAX_EXITS       8

/*  All details about a location */
struct LOCATION
{
	unsigned char id;
	char short_desc[SHORT_DESC_LEN];
	char long_desc[LONG_DESC_LEN];
	unsigned char exits[MAX_EXITS];
};

int loadLocationRecord()
{
	printf("Found Loc rec");
	return STATUS_OK;
}

int loadObjRecord()
{
	printf("Found Obj rec");
	return STATUS_OK;
}

void stripTrailingCR(char *line) 
{
    // Remove trailing newline if present
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') 
    {
        line[len - 1] = '\0';
    }
}

int loadGameData(void)
{
    /* Open the game date file for reading*/
    FILE *fp = fopen(FN_GAMEDATA, "r");
    if (!fp) 
    {
        /* Failed */
        printf("Failed to open file: %s\n", FN_GAMEDATA);
        return STATUS_FAIL;
    }

    /* Lets read the gamedata, line by line */
    char line[LONG_DESC_LEN];
    while (fgets(line, sizeof(line), fp)) 
    {
        stripTrailingCR(line);
        printf("Line: %s\n", line);
    }

    fclose(fp);
    return STATUS_OK;
}

int main(void)
{
	loadGameData();
	return STATUS_OK;
}