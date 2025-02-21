#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];
    int choice;
    printf("[1 <url>]To mp3\n[2 <url>]To mp4\n[3]Exit\n");
   
    while(1) {
    fgets(input, sizeof(input), stdin);
    choice = input[0] - '0';
    
    // Find first space
    char *urlStart = strchr(input, ' ');
    
    if (urlStart != NULL) {
        // Move past the space
        urlStart++;
        
        // Remove newline if present
        char *newline = strchr(urlStart, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        switch(choice) {
            case 1: {
                printf("Converting to MP3: %s\n", urlStart);
                char command[1024] = "";// Initialize to empty string
                strcat(command, "yt-dlp -x --audio-format mp3 ");
                strcat(command, urlStart);// Concatenate the command with the URL, required due to # of arguments system takes
                int result = system(command);
                
                if (result == 0) {
                    printf("FFmpeg command executed successfully\n");
                } else {
                    printf("FFmpeg command failed\n");
                }
                break;
            }
            case 2: {
                printf("Converting to MP4: %s\n", urlStart);
                char command[1024] = "";  //Initialize to empty string
                strcat(command, "yt-dlp --format mp4 ");
                strcat(command, urlStart);
                int result = system(command);
                
                if (result == 0) {
                    printf("FFmpeg command executed successfully\n");
                } else {
                    printf("FFmpeg command failed\n");
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } else {
        printf("No URL provided\n");
    }

}
return 0;
}