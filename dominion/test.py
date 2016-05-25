import subprocess
import sys


if len(sys.argv) != 4:
    print "test.py [path1] [path2] [seed]"
arr = []
subprocess.call("cp ./dominion.c ./dominion.c.original", shell=True)
arr.append( sys.argv[1] + 'dominion.c')
arr.append( sys.argv[2] + 'dominion.c')
seed = sys.argv[3]

subprocess.call("cp " + arr[0] + " ./dominion.c", shell=True)
subprocess.call("make clean; make testdom", shell=True)
subprocess.call("./testdominion "+seed+" > ./aaa", shell=True)
subprocess.call("gcov dominion.c  >> ./aaa", shell=True)




subprocess.call("cp " + arr[1] + " ./dominion.c", shell=True)
subprocess.call("make clean; make testdom", shell=True)
subprocess.call("./testdominion "+seed+" > ./bbb", shell=True)
subprocess.call("gcov dominion.c  >> ./bbb", shell=True)

r = subprocess.call("diff ./aaa ./bbb > difference.out", shell=True)
if (r != 0):
    print "TEST FAILED!"
else:
    print "TEST PASSED!"

subprocess.call("cp ./dominion.c.original ./dominion.c", shell=True)
