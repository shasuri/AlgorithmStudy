
class editor :
    def __init__(self,_text) :
        self.text = _text
        self.storage = []
        self.cursor = len(_text)

    def moveLeft(self) :
        if self.cursor > 0 :
            self.cursor -= 1
            self.storage.append(self.text.pop())
    
    def moveRight(self) :
        if self.cursor < len(self.text)+len(self.storage) :
            self.cursor += 1
            self.text.append(self.storage.pop())
        #print(self.text)

    def backspace(self) :
        if self.cursor > 0 :
            self.text.pop()
            self.cursor -= 1

    def paste(self,_character) :
        self.text.append(_character)
        self.cursor += 1

    def getBack(self) :
        #print(self.storage)
        for backIndex in range(len(self.storage)) :
            self.moveRight()
    


if __name__ == "__main__" :

    preText = list(input())

    textEditor = editor(preText)

    cmdNum = int(input())

    for cmdIndex in range(cmdNum) :
        command = input().split()

        if command[0] == 'L' :
            textEditor.moveLeft()
        
        if command[0] == 'D' :
            textEditor.moveRight()

        if command[0] == 'B' :
            textEditor.backspace()
        
        if command[0] == 'P' :
            textEditor.paste(command[1])

    textEditor.getBack()
    
    print(''.join(textEditor.text))

