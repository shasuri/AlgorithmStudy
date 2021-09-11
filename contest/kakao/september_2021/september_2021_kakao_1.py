class user :
    def __init__(self, name) :
        self.name = name
        self.reported = 0
        self.report_user = []
        self.reported_user = []
        self.mail = 0

def solution(id_list, report, k):
    user_list = {}
    for i in id_list :
        user_list[i] = user(i)
        
    for i in report :
        j = i.split()
        reporter = j[0]
        reportee = j[1]
        
        if reportee not in user_list[reporter].report_user :
            user_list[reporter].report_user.append(reportee)
            user_list[reportee].reported_user.append(reporter)
            user_list[reportee].reported += 1
    
    for i in id_list : 
        if user_list[i].reported >= k :
            for j in user_list[i].reported_user :
                user_list[j].mail += 1
    answer = []
    for i in id_list : 
        answer.append(user_list[i].mail)
    return answer
