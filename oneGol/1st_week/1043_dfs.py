
# https://www.acmicpc.net/problem/1043

class Person:
    def __init__(self, number):
        self.number = number
        self.partyAttend = []
        self.truth = False

    def attendParty(self, party):
        self.partyAttend.append(party)

    def getPartyAttend(self):
        return self.partyAttend

    def knowTruth(self):
        self.truth = True

    def getTruth(self):
        return self.truth


class Party:
    def __init__(self, people, peopleList):
        self.people = people
        self.peopleList = peopleList
        self.truth = False

    def getPeopleList(self):
        return self.peopleList

    def knowTruth(self):
        self.truth = True

    def getTruth(self):
        return self.truth


def searchTruth(partyList):

    for i in partyList:
        if not i.getTruth():
            i.knowTruth()
            for j in i.getPeopleList():
                p = peopleList[j-1]
                if not p.getTruth():
                    p.knowTruth()
                    searchTruth(p.getPartyAttend())


if __name__ == "__main__":
    firstLine = list(map(int, input().split(' ')))
    secondLine = list(map(int, input().split(' ')))

    peopleN = firstLine[0]
    partyM = firstLine[1]
    peopleList = []

    for i in range(peopleN):
        peopleList.append(Person(i+1))

    truePeople = secondLine[0]
    truePeopleList = secondLine[1:]

    # for i in truePeopleList:
    #     peopleList[i-1].knowTruth()

    lieParty = partyM
    partyList = []

    for i in range(partyM):
        partyLine = list(map(int, input().split(' ')))

        party = Party(partyLine[0], partyLine[1:])
        partyList.append(party)

        for j in party.getPeopleList():
            attendee = peopleList[j-1]
            attendee.attendParty(party)

    for i in truePeopleList:
        truePerson = peopleList[i-1]
        searchTruth(truePerson.getPartyAttend())

    for i in partyList:
        if i.getTruth():
            lieParty -= 1

    print(lieParty)
