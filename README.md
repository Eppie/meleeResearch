# meleeResearch
Researching modifications to Super Smash Brothers Melee

You'll need to install the toolchain for assembling your .c files into PowerPC assembly. To do so, run:

```bash
./devkitPPCupdate.pl
```

Then, try running the following:

```bash
./assemble.sh test.c
```

You should see a file generated, called test.s. You can open this file with asmwiird.exe and convert the assembly into Gecko code format.
