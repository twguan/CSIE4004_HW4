
import os
import sys

def read(filename):
    with open(filename, 'rb') as fp: return fp.read()

def run(ifn):
    #c = 'python3 -B AC_Code.py'
    # c = 'python -B ACCode.py'
    c = 'gpt.exe'
    # c = 'ACcode.exe'
    #c = 'main-wa-file.exe'
    #c = 'main-wa-std.exe'
    return os.system("%s < %s > %s"%(c,ifn,'slave.out'))

def main():
    score = 0
    for subtask in eval(read('subtasks.py')):        
        for trial in subtask[1:]:
            ifn, ofn, tl, ml, ol, dfn, wdfn, wdfn_ans = trial
            print('%s '%ifn, end='')
            res = run(ifn)
            ResStr = ''
            if res != 0:
                ResStr = 'RE 0'
            else:
                waLine = os.system('python ./special %s %s slave.out' % (ifn, ofn))
                waLinef = os.system('python ./special %s %s %s' % (ifn, wdfn, wdfn_ans))
                if waLine != 0:
                    ResStr = "WA-std 0"
                elif waLinef!= 0:
                    ResStr = "WA-file 0"
                else:
                    ResStr = "AC %d"%subtask[0]
                    score += subtask[0]
            print(ResStr)
    print(score)

if __name__ == '__main__':
    print('test\n')
    main()
    # input('press enter to continue...')