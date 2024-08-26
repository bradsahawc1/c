/*Cameron Bradshaw*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
This is a program that takes a file from the user along with a skip number and then 
removes the skipped letter/number throughout the file making a new one and then also
outputs the changes in size between the input and output.
*/

main()
{
	char x;				                                                       // current char
	int countForSkip = 1;                                                      //counter to tell when to skip
	int countRemaining = 0;                                                    //counter to tell me how many characters are left after the skip
	int countAll =	0;                                                         //counts the original size of the file
	float sizeChange;                                                          //the variable for the percentage of change
	int skipNum;                                                               //the input variable that tells me when to skip

	printf("Enter the skip number: ");                                         //ask user for the skip number
	scanf("%d", &skipNum);                                                   //user enters the number for the skip

	FILE* fp1, * fp2;                                                          //fp1, will point to the input file, fp2 will point to the output file
	char filename[100];		                                                   //filename
	printf("Enter the filename to be scanned: ");	                           //ask user for filename
	scanf("%s", filename);                                                     //user enters the file name to be used
	fp1 = fopen(filename, "r");	                                               //open input file, read-only
	fp2 = fopen("output.txt", "w");	                                           //open output file, write-only

	while ((x = getc(fp1)) != EOF)	                                           //get next char from input file, store in x, until we reach EOF
	{
		if (x == ' ' || x == '\n' || x == '\t' || ispunct(x)) {                //if the character is something other than a letter or number
			fputc(x, fp2);                                                     //puts the character down and all counters go up one except for the skip counter
			countAll++;
			countRemaining++;
		}
		else {
			if (!(countForSkip %= skipNum)) {                                  //if the skip number is divisble with the counter then you skip the character
				countAll++;
				countForSkip++;
			}
			else {                                                             //otherwise every counter goes up and the character gets written down
				fputc(x, fp2);
				countAll++;
				countForSkip++;
				countRemaining++;
			}
		}
	}

	fclose(fp1);                                                               //close the readable file
	fclose(fp2);                                                               //close the new written file

	sizeChange = ((float)countRemaining / countAll) * 100;                     //calculate the percentage of change between the two files

	printf("\n");                                                              //the print statements for the sizes and the percentage
	printf("Size of infile.txt: %13s%d", "", countAll);
	printf("\n");
	printf("Size of outfile.txt: %12s%d", "", countRemaining);
	printf("\n");
	printf("File size change: %15s%.2f%%", "", sizeChange);
	printf("\n");
}

/*
Enter the skip number: 7
Enter the filename to be scanned:  infile2.txt

Size of infile.txt:              632
Size of outfile.txt:             563
File size change:                89.08%

I am the eaven
I m the waer
Ich bn der Drck unte deinen alzen
(O no, whip t on me, hney!)
Ich in dein eheime Schmut
Und verorenes etallgld
(Metalgeld)
Ih bin dene Ritz
Ich bin eine Rize und Shlitze

 am the couds
I a embroiered
Ic bin der utor aler Felgn
Und Daast Paseln
Ich in der Crome Diette
Ic bin der hrome Dnette
Ih bin Eir aller rten

Ic bin all Tage un Nachte
ch bin ale Tage nd Nache

Ich bi hier (Aie-Ah!)
Und u bist min Sofa
ch bin her (Aiee-h!)
Und du ist mei Sofa
Ic bin hie (Aiee-Ah!)
nd du bit mein Sfa

Yeah-a-ha-ay
Yh-ha
Yea, my Sofa
eah-ha-hy

Enter the skip number: 3
Enter the filename to be scanned:  infile3.txt

Size of infile.txt:              2369
Size of outfile.txt:             1750
File size change:                73.87%

Oho Sat ha tune wht's non a Th Gae ito TS am, main on of he retet rvaris i sprt a oe-sde seie wih ltte sspns.
Chsig a atonl camioshp, nt smpy batng he olerne, is ow he uceys masre  sucesfl sasn.
Ad ude fist-ea coch ya Da, thy hve ut heseve in  poiton o ptetill wi it ll or he ecnd im sice he 01 seso an thrd im ths cntry.
.K. Dbbns an or ou tochows ad Jstn Fels tre for T pase, prviin plnt of irpoer or o. 2 hi Stte o rut o. 1 Mihian 6-2 Sauray or  scoo-reor eiht staiht in n te sris.
"I fels ret jst o cntnu th leac of hi grat hi Stte raiton," efnsve nd hae Yun sad. "W're us gong o ty t kep i moin an kep i rolig nxt ee."
Th Bukees (2-0, -0 Bg Tn, N. 1 CP) wll ea to he ig en hapinsip am to ac No. 3 Wscnsn nxt atrdy wth  spt i th Colee Fotal Plyof i siht.
ieds il liel us th liitd tme o rst nd es ou brce to roec hi let kee ha wa inurd fr a ecnd trigt wek.
e wnt ow in he hid qarer nd inery wlkd of te fel to et vauaed n a en bein Oho Sat's sdein. He am bak i th gae ate a fw pay an on he ex snp, srabld ad tre a 3-yad tucdon pss o Grrtt ilon.
"t ws a agca moen," Da sad. "I hogh it as  Hesmn mmet."
Fels hs tron 3 tochow pase wih oly ne ntrcpton nd coed 0 mre ims rshng.
he opomre uatebak sid e agrvaed  staied igmet, frcng im o ue a uly bac afer tatig te gme it a saler ne, ut id't cnsde styig ot o th gae.
"I aned o sow he ea I ws tug," he ai.
Th Woveins (9-, 6-3, o. 1 CF) wil hve o stte fr a ecnd- r tir-tir bwl am afer oah Jm Hrbug fel t 0-5 n te rvary, nd he rora lot t Oho Sat fo th 15h tme n 1 yers.
"t's us kid o th sae tin evry ea," Mihian igt ed San cKon ai. "It et ol, bu yo've us go to la bete agint tem.
arauh ws ake if he ifernc bewen te tam wa taen, prpaaton r cacin?
"I'l anwe yor qesios, bt nt yur nslt," Habagh ai to  reorer.
*/