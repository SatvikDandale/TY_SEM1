import json

class node:
    # This is just a structure
    def __init__(self):
        self.data = ''
        self.freq = 0
        self.left = None
        self.right = None
# End of class


class HuffmanDecoding:
    
    def getKey(self, n):
        # Utility function for sorting the nodes according to their frequencies
        return n.freq

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
    

    def extractText(self):
        # This function is used to extract text from encoded binary string
        # We will use the huffman tree to detect the end of the bits sequence for a character
        current = self.root
        self.finalString = ""
        i = 0
        while i < len(self.binaryString):
            bit = self.binaryString[i]
            # Check if current represents a character
            if current.data != '-':
                print("Found ", current.data)
                # then it is a character
                self.finalString += current.data
                current = self.root
                continue
            # Else it is an internal node
            print("Current bit is: ", bit)

            if bit == '0':
                print("Going left\n")
                current = current.left
            else:
                print("Going right\n")
                current = current.right
            i += 1
        
        if current.data != '-':
            print("Found ", current.data)
            # then it is a character
            self.finalString += current.data

    def extractBinary(self, encodedString):
       
        # function :
        #   1. convert char to ascii
        #   2. ascii to binary
        #   3. remove padding
        #   4. concatenate into 1 string
        self.binaryString = ""
        self.extraZeroes = int(encodedString[0])
        for i in range(1, len(encodedString)):
            temp = bin(ord(encodedString[i]))
            print(temp)
            self.binaryString += temp[2:]

        self.binaryString = self.binaryString[0: len(self.binaryString)-self.extraZeroes]
        print(self.binaryString)
        self.createTree()
        self.extractText()

    def __init__(self, data):
        self.charDict = data



def main():
    with open('metadata.json') as file:
        data = json.load(file)

    d = HuffmanDecoding(data)

    with open("compressed.dat", "r") as file:
        text = file.read()
    d.extractBinary(text)

    with open("decompressed.txt", 'w') as file:
        file.write(d.finalString)

if __name__ == "__main__":
    main()