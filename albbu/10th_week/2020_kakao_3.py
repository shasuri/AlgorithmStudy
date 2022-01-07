from copy import copy
def solution(info, query):
    answer = []
    class applicant :
        def __init__(self,_appIndex) :
            self.appIndex = _appIndex

            self.lang = None
            self.type = None
            self.career = None
            self.food = None
            self.score = None
            
            
        def setLang(self,_lang) :
            self.lang = _lang
        
        def setType(self,_type) :
            self.type = _type
        
        def setCareer(self,_career) :
            self.career = _career

        def setFood(self,_food) :
            self.food = _food

        def setScore(self,_score) :
            self.score = _score

    appList = []
    appSize = len(info)

    for infoIndex in range(appSize) :
        singleInfo = info[infoIndex].split()
        
        singleApp = applicant(infoIndex)
        
        singleApp.setLang(singleInfo[0])
        singleApp.setType(singleInfo[1])
        singleApp.setCareer(singleInfo[2])
        singleApp.setFood(singleInfo[3])
        singleApp.setScore(int(singleInfo[4]))

        appList.append(singleApp)

    querySize = len(query)

    for queryIndex in range(querySize) :
        singleQuery = query[queryIndex].split()
        singleQuery[-1] = int(singleQuery[-1])
        checkIndex = -1
        checkList = copy(appList)
        tempList = []
        tempListTwo = []
        
        while True :
            for appIndex in range(len(appList)) :
                if singleQuery[0] == "-" or singleQuery[0] == appList[appIndex].lang :
                    tempList.append(appList[appIndex])

            if len(tempList) == 0 :
                ans = 0
                break

            for appIndex in range(len(tempList)) :
                if singleQuery[2] == "-" or singleQuery[2] == tempList[appIndex].type :
                    tempListTwo.append(tempList[appIndex])
            tempList = []
            
            if len(tempListTwo) == 0 :
                ans = 0
                break

            for appIndex in range(len(tempListTwo)) :
                if singleQuery[4] == "-" or singleQuery[4] == tempListTwo[appIndex].career :
                    tempList.append(tempListTwo[appIndex])
            tempListTwo = []
            
            if len(tempList) == 0 :
                ans = 0
                break

            for appIndex in range(len(tempList)) :
                if singleQuery[6] == "-" or singleQuery[6] == tempList[appIndex].food :
                    tempListTwo.append(tempList[appIndex])
            tempList = []
            
            if len(tempListTwo) == 0 :
                ans = 0
                break

            for appIndex in range(len(tempListTwo)) :
                if singleQuery[7] <= tempListTwo[appIndex].score :
                    tempList.append(tempListTwo[appIndex])
            ans = len(tempList)
            break
        
        answer.append(ans)
    
        
    return answer
