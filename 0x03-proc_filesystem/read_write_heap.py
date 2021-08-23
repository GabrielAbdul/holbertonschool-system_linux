#!/usr/bin/python3
'''read_write_heap module'''

from sys import argv


def printUsageAndExit():
    '''prints usage error and exits'''
    print("Usage: {} PID SEARCH WRITE".format(argv[0]))
    exit(1)


def findHeapAddress(pid):
    '''searces /proc/pid/maps file for addr of heap'''
    maps = '/proc/{}/maps'.format(pid)
    try:
        with open(maps, 'r') as file:
            for line in file:
                if 'heap' in line:
                    addr = line.split(' ')[0]
                    print("Address of heap:", addr)
                    return addr
    except Exception as e:
        print(e), exit(1)


def replaceStringInHeap(pid, search, replace, addr):
    '''seeks for search string in mem file of pid, and replaces it'''
    print("searching for:", search)
    mem = '/proc/{}/mem'.format(pid)
    start, stop = int(addr.split('-')[0], 16), int(addr.split('-')[1], 16)
    print('Heap found!', 'Searching for string!')
    try:
        with open(mem, 'rb+') as file:
            file.seek(start)
            heap = file.read(stop - start)
            string = heap.index(bytes(search, "ASCII"))
            print('Found:', search)
            file.seek(start + string)
            file.write(bytes(replace, "ASCII"))
            print('Replacing {} with {}'.format(search, replace))
    except Exception as e:
        print(e), exit(-1)


if __name__ == '__main__':
    if len(argv) != 4:
        printUsageAndExit()
    addr = findHeapAddress(int(argv[1]))
    replaceStringInHeap(int(argv[1]), argv[2], argv[3], addr)
