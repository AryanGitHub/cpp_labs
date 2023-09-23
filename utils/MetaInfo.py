import os.path
import sys


class MetaInfo:

    # This class is used to parse the information from the "experiment.cpp" file's 1st Multiline comment.
    # The 1st Multiline is expected to have the meta information about the experiment
    #
    # In future if you want to add new tags for meta information, it can be easily done by doing these steps:
    # Step 1: add the New <tag-Name> as defined in the cpp file, to the last of the tags tuple, i.e. it should be the last element of the tuple
    # Step 2: add an attribute filed in the constructor like self.newlyAddedAttributeName
    # Step 3: set it `MetaInfo.extractTagInfo(removedSymbols, <IndexOfNewlyAddedTagInTagsTuple>)`
    # Done

    # If the tag is not found, then it returns an empty string

    tags = ("Tags", "Aim", "Other Tags", "Additional Information")  # tags are case-sensitive

    def __init__(self, pathToFolder):
        # it accepts a path to the folder, and assumes the folder is containing "experiment.cpp" file.

        self.pathToFile = MetaInfo.__getPathToFile__(pathToFolder)
        # this is the "experiment.cpp" file path

        if (self.__isValidFile__()):

            multiLineComment = self.__get1stMultiLineComment__()
            removedSymbols = MetaInfo.removeStarsAndMultiLineSymbol(multiLineComment)

            self.tags = MetaInfo.extractTagInfo(removedSymbols, 0)
            self.aim = MetaInfo.extractTagInfo(removedSymbols, 1)
            self.otherTags = MetaInfo.extractTagInfo(removedSymbols, 2)
            self.additionalInfo = MetaInfo.extractTagInfo(removedSymbols, 3)

        else:
            sys.exit(self.pathToFile + " do not exists!")
            # if the file does not exist, the program exits.

    def __getPathToFile__(path):
        # converts a path to folder to a path to an experiment file path
        return path + os.sep + "experiment.cpp"

    def __isValidFile__(self):
        # checking if file "experiment.cpp" exists
        return os.path.isfile(self.pathToFile)

    def __get1stMultiLineComment__(self):
        # this function returns the first multiline comment in the experiment file.
        # this comment is expected to have meta-information about the experiment.
        ret = ""
        fileReader = open(self.pathToFile, "r")
        startComment = False
        while True:
            data = fileReader.readline()
            if (data.find("/*") != -1):
                startComment = True
            if (startComment):
                ret += data
                if (data.find("*/") != -1):
                    break
        ret = ret[ret.find("/*"): ret.find("*/") + 2]
        return ret

    def removeStarsAndMultiLineSymbol(multiLineComment):
        # this function removes symbols like:
        # /* (start multi line comments) or */ (end of multi line comment)
        # star symbol from each line *
        # space
        # Note: the function do not remove the space in between the lines, inorder to preserve indentation

        ret = multiLineComment[multiLineComment.find("/*") + 2: multiLineComment.find("*/")]
        lines = ret.replace("*", "").strip()
        lines = lines.split("\n")
        for lineNumber in range(len(lines)):
            line = lines[lineNumber]
            # line = line.strip()  # in order to preserve indentation, this source code line is commented.
            if (len(line) != 0):
                lines[lineNumber] = line + "\n"
        ret = "".join(lines).strip()
        return ret

    def hasATagAndColonOfIndex(line, indexOfTag):
        # this function is used to check if the given tag is present in a given line or not.
        # the first parameter is the given line,
        # the second parameter is the index of given tag.
        # the index is given from tags tuple

        # Tag is found if and only if
        # <tag name> present in the line, and it is followed by a colon symbol ":"
        # some valid examples
        # <tag_name> : like =>  "greet : hi , hola"
        # <tag_name> <some other data> : "like => test (optional) : this is a test line"

        x = MetaInfo.tags[indexOfTag]  # x is tag_name
        tagFoundPos = line.find(x)
        if (tagFoundPos != -1):
            colonFoundPos = line.rfind(":")
            return colonFoundPos > tagFoundPos
        else:
            return False
    def hasAnyTagAndColon(line):
        # this function is used to know if any tag is present on the given line of not.
        # this function is being used in `extractTagInfo function` in order to get info till which line a tag has scope
        # a tag continues till the next tag is found, or end of string
        for i in range(len(MetaInfo.tags)):
            if (MetaInfo.hasATagAndColonOfIndex(line, i)):
                return True
        else:
            return False



    def extractTagInfo(processedLines, indexOfTag):
        # this function is used to get the information or data of the given tag.

        # `processedLines` is the data returned after removeStarsAndMultiLineSymbol function
        # `indexOfTag` is the index from the tags tuple, which data has to be extracted.
        # The tags are case-sensitive.
        # If the tag is not found, empty string is returned.

        lines = processedLines.split("\n")
        tagData = ""
        for lineNumber in range(len(lines)):
            if (MetaInfo.hasATagAndColonOfIndex(lines[lineNumber], indexOfTag)):
                tagData += lines[lineNumber] + "\n"
                lineNumber += 1
                while (lineNumber < len(lines) and (not MetaInfo.hasAnyTagAndColon(lines[lineNumber]))):
                    lineToAdd  = lines[lineNumber] + "\n"
                    tagData += lineToAdd
                    lineNumber += 1
                break
        tagData = tagData[tagData.rfind(":") + 1:].strip()
        return tagData

    def toString(self):
        # this function is used get all tags extracted data.
        ret = f'Tags : {self.tags}\nAim : {self.aim}\nOther Tags : {self.otherTags}\nAdditional Information : {self.additionalInfo}'
        return ret


def main():
    folderPath = sys.argv[1] # assuming 1st parameter is a path to the experiment folder, if this is standalone file running
    data = MetaInfo(folderPath)
    print(data.toString())


if __name__ == '__main__':
    main()
