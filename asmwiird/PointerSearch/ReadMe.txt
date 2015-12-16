PointerSearch 'hacker edition' v3 by Dr.Pepper
-----------------------------------------------------
PointerSearch v3 is standalone console application which is much faster than wiird pointer search.
It can combine 80&90 dumps and even search 3rd dumpset in comparision (to remove false positives if
you get too many matches). 

Default dump file locations are in dump1, dump2 and dump3 -dirs.
There are 6 valid dump file combinations:
--
data1\dump_80.bin
data2\dump_80.bin
data3\dump_80.bin (optional)
--
data1\dump_90.bin
data2\dump_90.bin
data3\dump_90.bin (optional)
--
data1\dump_80.bin + data1\dump_90.bin
data2\dump_80.bin + data2\dump_90.bin
data3\dump_80.bin + data3\dump_80.bin (optional)
--
Linux prerequisite in ubuntu 10.04 install Qt 4.6.2 # apt-get install libqt4-dev
MacOs prerequisite: install Qt 4.7.0 from http://qt.nokia.com/downloads

Usage (PointerSearch.exe Windows, PointerSearch.Linux or PointerSearch.MacOS -binary depending on your OS) 
(chmod a+x if needed) and run:
# PointerSearch 0xPointer1 0xPointer2 0xPointer3 0xOffset

Examples, if you have dump files in data1, data2 -dirs (filenames can be configured in .cfg, 
defaults to dump_80.bin and dump_90.bin (other one can be missing, depending if your doing mem80, 
mem90 or combined mem80&90 search)). For example if you have data1/dump_80.bin and data2/dump_80.bin:

                dump1ptr   dump2ptr   dump3ptr   offset
# PointerSearch 0x80123456 0x80654321 0x00000000 0x8000

(3rd parameter 0x0 is ignored if data3 dir is empty, if you have dump in data3 then you would put 
3rd pointer instead of 0x00000000). 

-----------------------------------------------------
Example: Brothers in Arms - Road to Hill30 [RI8P41]
-----------------------------------------------------
This is great example to debug, since the pointer in pointer value is in 80-dump and 
the location of the riffle ammo on screen / total ammo is in 90-dump. As that pointer 
changes between chapters, ie you need to generate pointer in pointer code which 
combines 80&90-dumps (wiird pointer in pointer search cannot do combined searches).

You start playing some chapter and fire up wiird/gecko dotNET. Unknown value search, 
and then "different by 1"-searches after shooting one shot by time, and you notice 
that there are no hits in 80-area, so you switch to 90-area and start the searching 
"different by 1" again. And finally you find the gun ammo on the screen, and below 
that the total gun ammo, so you mark the pointers down and take memory 80 & 90 dumps 
and save them into "data1\dump_80.bin" and "data1\dump_90.bin". Then you goto different chapther
and redo the steps and save corresponding dumps to "data2\dump_80.bin" and "data2\dump_90.bin". 
If you get too many matches then you can repeat the steps in some other chapther and 
put that data in data3-dir.

Chapter X
0x901c0dF4 on screen
0x901c2214 total ammo

Chapter Y
0x901be694 on screen
0x901bf8b4 total ammo

Now you fire up pointer search application from command prompt/shell:
----
C:\PointerSearch>PointerSearch.exe 0x901c2214 0x901bf8b4 0x0 0x800
PointerSearch v2 Copyright-2008,2009,2010 Dr.Pepper

Searching for data1/dump_80.bin...found.
Searching for data2/dump_80.bin...found.
Searching for data3/dump_80.bin...file not found.
Searching for data1/dump_90.bin...found.
Searching for data2/dump_90.bin...found.
Searching for data3/dump_90.bin...file not found.
Processing data1_80 into database: ...............
Processing data1_90 into database: ..................................
Processing data2_80 into database: ...............
Processing data2_90 into database: ..................................
Processing data3_80 into database:
Processing data3_90 into database:
No matches found in simple pointer search... moving to pointer in pointer mode.
This might take arout 1-20 minutes or so, depencing on your processor, memory speed
and offset value. So be patient...
MATCH: ((803f937c+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f937c+64)[==Fx803f937c,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f937c+64)+2b4] in your pointer in pointer code.
MATCH: ((803f9380+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9380+64)[==Fx803f9380,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f9380+64)+2b4] in your pointer in pointer code.
MATCH: ((803f942c+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f942c+64)[==Fx803f942c,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f942c+64)+2b4] in your pointer in pointer code.
MATCH: ((803f9430+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9430+64)[==Fx803f9430,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f9430+64)+2b4] in your pointer in pointer code.
MATCH: ((803f937c+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f937c+2c8)[==Fx803f937c,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f937c+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f9380+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9380+2c8)[==Fx803f9380,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f9380+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f942c+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f942c+2c8)[==Fx803f942c,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f942c+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f9430+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9430+2c8)[==Fx803f9430,Px901be2e0]+2b4) ==Px901bf8b4
USE: [(0x803f9430+2c8)+2b4] in your pointer in pointer code.
Found 8 matches. (18secs)
Total time spend 346s
----
Was using the total ammo in this example, as that can only be found in pointer in pointer mode.
On screen ammo seems to be easier and can be found in faster simple pointer search
(which can be more error prune for crashing as "pointer in pointer" is way more reliable between chapters).
----[v3 example]---------------------------------------------------------------------
C:\pointersearch\release>PointerSearch.exe 0x901c2214 0x901bf8b4 0x901bf0b4 0x8000
PointerSearch v3 Copyright-2008,2009,2010 Dr.Pepper

Searching for data1/dump_80.bin...found.
Searching for data2/dump_80.bin...found.
Searching for data3/dump_80.bin...found.
Searching for data1/dump_90.bin...found.
Searching for data2/dump_90.bin...found.
Searching for data3/dump_90.bin...found.
Processing data[123] dumps into database: [221321323121322221322222231223122222221331313131131331333313333311111111]

No matches found in simple pointer search... moving to pointer in pointer mode.

MATCH: ((803f9430+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9430+2c8)[==Fx803f9430,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f9430+2c8)[==Fx803f9430,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f9430+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f942c+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f942c+2c8)[==Fx803f942c,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f942c+2c8)[==Fx803f942c,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f942c+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f9380+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9380+2c8)[==Fx803f9380,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f9380+2c8)[==Fx803f9380,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f9380+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f937c+2c8)[==Fx901c0d08,Px901c1f60]+2b4) ==Px901c2214
* data2((803f937c+2c8)[==Fx803f937c,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f937c+2c8)[==Fx803f937c,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f937c+2c8)+2b4] in your pointer in pointer code.
MATCH: ((803f9430+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9430+64)[==Fx803f9430,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f9430+64)[==Fx803f9430,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f9430+64)+2b4] in your pointer in pointer code.
MATCH: ((803f942c+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f942c+64)[==Fx803f942c,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f942c+64)[==Fx803f942c,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f942c+64)+2b4] in your pointer in pointer code.
MATCH: ((803f9380+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f9380+64)[==Fx803f9380,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f9380+64)[==Fx803f9380,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f9380+64)+2b4] in your pointer in pointer code.
MATCH: ((803f937c+64)[==Fx901c0aa4,Px901c1f60]+2b4) ==Px901c2214
* data2((803f937c+64)[==Fx803f937c,Px901be2e0]+2b4) ==Px901bf8b4
* data3((803f937c+64)[==Fx803f937c,Px901bd880]+2b4) ==Px901bf0b4
USE: [(0x803f937c+64)+2b4] in your pointer in pointer code.
Found 8 matches. (2secs)
Total time spend 39s
-------------------------------------------------------------------------------------
GUI version of this application is under development, stay tuned...
