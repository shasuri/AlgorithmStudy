def solution(new_id):
    
    new_id = new_id.lower()
    temp_id = ""

    for strIndex in range(len(new_id)) :
        
        if not new_id[strIndex].isalnum() :
            if new_id[strIndex] == '-' or new_id[strIndex] == '_' or new_id[strIndex] == '.' :
                temp_id += new_id[strIndex]

        else :
            temp_id += new_id[strIndex]
        
    new_id = temp_id
    
    temp_id = ""
    dotCount = 0
    for strIndex in range(len(new_id)) :
        
        if new_id[strIndex] == "." :
            if dotCount == 0 :
                temp_id += "."
            
            dotCount += 1

        else :        
            temp_id += new_id[strIndex]
            dotCount = 0
        
    temp_id = temp_id.strip('.')

    strSize = len(temp_id)

    if strSize == 0 :
        temp_id += "a"
        strSize += 1

    if strSize > 15 :
        temp_id = temp_id[:15]
        temp_id = temp_id.rstrip('.')
        strSize = 15

    if strSize <= 2 :
        last_char = temp_id[-1]
        
        for strIndex in range(3 - strSize) :
            temp_id += last_char
    
    answer = ''
    answer = temp_id
    return answer
