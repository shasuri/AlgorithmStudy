def solution(new_id):
    
    new_id = new_id.lower() # step1
    
    temp_id = ""

    for strIndex in range(len(new_id)) :    
        if not new_id[strIndex].isalnum() : # step2, 소문자 제외
            if new_id[strIndex] == '-' or new_id[strIndex] == '_' or new_id[strIndex] == '.' :
                temp_id += new_id[strIndex] # step2, -_. 제외

        else :
            temp_id += new_id[strIndex] # 제외된 문자 추가
        
    new_id = temp_id
    
    temp_id = ""
    dotCount = 0
    for strIndex in range(len(new_id)) : # step3, .줄이기
        
        if new_id[strIndex] == "." :
            if dotCount == 0 :
                temp_id += "."
            
            dotCount += 1

        else :        
            temp_id += new_id[strIndex]
            dotCount = 0
        
    temp_id = temp_id.strip('.') # step4

    strSize = len(temp_id)

    if strSize == 0 : # step5
        temp_id += "a"
        strSize += 1

    if strSize > 15 : # step6
        temp_id = temp_id[:15]
        temp_id = temp_id.rstrip('.')
        strSize = 15

    if strSize <= 2 : # step7
        last_char = temp_id[-1]
        
        for strIndex in range(3 - strSize) :
            temp_id += last_char
    
    answer = ''
    answer = temp_id
    return answer
