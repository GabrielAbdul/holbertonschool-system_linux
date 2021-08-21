#!/usr/bin/python3
'''read_write_heap module'''

from sys import argv

def printUsageAndExit():
    '''prints usage error and exits'''
    print("Usage: {} PID SEARCH WRITE".format(argv[0]))
    exit(1)

def findHeapAddress(pid):
    '''searces /proc/pid/maps file for address of heap'''
    maps = '/proc/{}/maps'.format(pid)
    try:
        with open(maps, 'r') as file:
            for line in file:
                if 'heap' in line:
                    address = line.split(' ')[0]
    except Exception as e:
        print(e)
    print("Address of heap:", address)
    return address

def replaceStringInHeap(pid, search, replace, address):
    '''seeks for search string in mem file of pid, and replaces it'''
    return

if __name__ == '__main__':
    if len (argv) != 4:
        printUsageAndExit()
    address = findHeapAddress(int(argv[1]))
    replaceStringInHeap(int(argv[1]), argv[2], argv[3], address)