import subprocess
import sys
import random

def runsubprocess(out,err):
    subprocess.call(["make","clean"],stdout = out,stderr=err)
    subprocess.call(["make","all"],stdout = out,stderr=err)
    subprocess.call(["make","tarantulatestdom"],stdout = out,stderr=err)
    Randseed = random.randint(1,10000)
    return subprocess.call(["./tarantulatestdominion",str(Randseed)],stdout=out,stderr=err)    

def getLines(f):
    x = 0
    for l in f.readlines():
        x = x +1
    return x
        

def main():
    Tests = 50
    #Create our files to redirect stderr and stdout
    Mystdout = open("stdout.txt","w")
    Mystderr = open("stderr.txt","w")
    runsubprocess(Mystdout,Mystderr)
    subprocess.call(["gcov","dominion.c"],stdout=Mystdout,stderr=Mystderr)
    domfile = open("dominion.c.gcov","r")
    Lines = getLines(domfile)
    print Lines
    domfile.close()
    passedTests = 0
    failedTests = 0
    passedLines = [0] * Lines
    failedLines = [0] * Lines
    susp = [0] *Lines
    suspiciousness = []
    for i in range(Tests):
        ExitStatus = runsubprocess(Mystdout,Mystderr)
        subprocess.call(["gcov","dominion.c"],stdout=Mystdout,stderr=Mystderr)        
        if ExitStatus != 0:
            #print "exit code: %d" %(ExitStatus)
            failedTests = 1 + failedTests
        else:
            #print "pass"
            passedTests = 1 + passedTests
        gcovfile = open("dominion.c.gcov","r")
        
        for index,line in enumerate(gcovfile):
            if(line[8] !="#" and line[8] !="-"):
                if ExitStatus != 0:
                    failedLines[index] = failedLines[index] + 1
                else:
                    passedLines[index] = passedLines[index] + 1
            
            
        gcovfile.close()
    print "Passed Tests: %d Failed Tests: %d" %(passedTests,failedTests)
    for i in range(Lines):
        # to avoid division by 0
        if(failedLines[i] > 0 and passedLines[i] > 0):
            susp[i] = (float(failedLines[i])/float(failedTests))/( (float(passedLines[i])/float(passedTests)) + (float(failedLines[i])/float(failedTests))  )
    susp = susp[4:len(susp)]
    for i in range(len(susp)):
        suspiciousness.append( [i,susp[i]] )
    suspiciousness.sort(key=lambda tup: tup[1], reverse=True)
    for line,percentage in (suspiciousness):
        if percentage > 0:
            print "suspiciousness %f Line %d" %(percentage,line)
    Mystdout.close()
    Mystderr.close()

if __name__ == "__main__":
    main()