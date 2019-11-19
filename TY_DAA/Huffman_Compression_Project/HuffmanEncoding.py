import json

class node:
    # This is just a structure
    def __init__(self):
        self.data = ''
        self.freq = 0
        self.left = None
        self.right = None
# End of class

class HuffmanEncoding:
    def getKey(self, n):
        # Utility function for sorting the nodes according to their frequencies
        return n.freq

    def saveDict(self, node, s):
        try:
            self.charCodes
        except:
            self.charCodes = {}
        # This function will print the char, freq, corresponding code
        if node.left == None and node.right == None and node.data != '-':
            # We have a valid character at this node
            self.charCodes[node.data] = s
            # print(node.data, ": ", node.freq, "->", s)
            return
        self.saveDict(node.left, s + "0")
        self.saveDict(node.right, s + "1")

    def createDict(self, text):
        # This function will create a char: freq pair from the given text.
        tempDict = {}
        for char in text:
            if char in tempDict:
                tempDict[char] += 1
            else:
                tempDict[char] = 1
        return tempDict

    def createTree(self):
        # This function will create a Huffman Tree with the given char: freq combination.
        node_list = []
        # Creating a list of nodes
        for data in self.charDict:
            freq = self.charDict[data]
            n = node()
            n.data = data
            n.freq = freq
            node_list.append(n)
        # End of for loop
        node_list = sorted(node_list, key = self.getKey)

        # Start creating the tree
        self.root = node()
        
        while len(node_list) > 1:
            # Take two nodes of lowest frequency
            a = node_list[0]
            b = node_list[1]

            node_list.pop(0)    # Remove a 
            node_list.pop(0)    # Remove b

            temp = node()
            # Create a new node with children being the previous two nodes.
            temp.data = '-'
            temp.freq = a.freq + b.freq # Add the frequencies
            temp.left = a
            temp.right = b

            self.root = temp

            node_list.append(temp)
            # The node with lower frequency should come first
            node_list = sorted(node_list,  key = self.getKey)   
        
    def convertTextToBinary(self, text):
        # This function will iterate over the text and for each character visited, the character will be replaced by its corresponding binary code
        self.binaryString = ""
        self.lenBinary = 0  # To store the length of binary string. (Verifying for multiple of 8)
        for char in text:
            self.lenBinary += len(self.charCodes[char])
            # For each character
            self.binaryString += str(self.charCodes[char]) # Adding each bit code to the binary stream
        # Aftet this loop, the entire text is converted into a string of binary numbers.
        # Make sure that the length of this binary string is a multiple of "8". (BYTE ADDRESSABLE MEMORY)
        # If not, add remaining zeros(0s) at the end and keep count of it.
        
        self.extraZerosAtEnd = 8 - self.lenBinary % 8
        for _ in range(self.extraZerosAtEnd):
            self.binaryString += "0"    # Adding necessary zeroes at the end.

    def customEncoding(self):
        self.dividedBinary = [] # This will store binary values which are divided in 8 digits
        self.finalString = ""   # Final Encoded String

        for i in range(0, len(self.binaryString), 8):
            temp = self.binaryString[i:i+8]
            self.dividedBinary.append(temp)
            ascii = int(temp, 2)
            self.finalString += chr(ascii)


    def __init__(self, text):
        self.charDict = self.createDict(text)
        self.createTree()
        self.saveDict(self.root, "")
        self.convertTextToBinary(text)
        self.customEncoding()


def main():
    # temp = {
    #     "b" : 9,
    #     "a" : 5,
    #     "f" : 45,
    #     "c" : 12,
    #     "d" : 13,
    #     "e" : 16
    # }
    with open('sampleText.txt', 'r') as file:
        text = file.read()

    h = HuffmanEncoding(text)
    # This object "h" has the encoded version of the given text with the huffman tree, char: freq pairs and char: huffman bit code pairs stored. Save the charCodes dictionary in a JSON file.
    
    with open('compressed.dat', 'w') as file:
        file.write(str(h.extraZerosAtEnd))
        file.write(h.finalString)
    
    with open('metadata.json', 'w') as file:
        json.dump(h.charDict, file, indent = 2)

    print(h.binaryString[:len(h.binaryString)-h.extraZerosAtEnd])

if __name__ == '__main__':
    main()
