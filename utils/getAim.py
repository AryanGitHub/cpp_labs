import sys
from MetaInfo import MetaInfo


def main():
    folderPath = sys.argv[1]
    # assuming 1st parameter is a path to the experiment folder, if this is standalone file running
    data = MetaInfo(folderPath)
    print(data.aim)


if __name__ == '__main__':
    main()
