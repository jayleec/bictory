import xml.etree.ElementTree as ET

def cal_complexity(child2):
    sumofcom = 0
    # number of statements less 9 = 0
    if float(child2[15].text) < 9:
        sumofcom += 9
        print("sumofcom = ", sumofcom)
    if float(child2[2].text) < 50:
        sumofcom += 9
    if float(child2[1].text) < 35:
        sumofcom += 9
    if float(child2[4].text) < 120:
        sumofcom += 9
    if float(child2[3].text) < 140:
        sumofcom += 9
    if 3 <= float(child2[7].text) <= 75:
        sumofcom += 9
    if 3 <= float(child2[5].text) <= 250:
        sumofcom += 10
    if float(child2[20].text) < 8:
        sumofcom += 9
    if float(child2[25].text) < 15:
        sumofcom += 9
    if float(child2[19].text) < 9:
        sumofcom += 9
    if float(child2[16].text) < 7:
        sumofcom += 9
    return sumofcom


tree = ET.parse("/Users/jay/torch_5th/home/static/data/crulechk.0.xml")
root = tree.getroot()

print(root)

# 메트릭 개수는 항상 27개
# 전체 파일 개수
sumOfTheNumberOfFunctions = 0
numberOfFile = 0
totalCpntLenOfFunction = 0
averageCpntLenOfFile = 0
cpntLenOfFunction = 0
numberOfFunction = 0
totalCpntLenOfProject = 0

complexity = 0
maintainability = 0
structuredness = 0
testability = 0

for child in root:
    numberOfFile += 1
    sumOfTheNumberOfFunctions += len(child[1])
    print("File Path : ", child[0].text)  # 파일 경로 출력

    for child2 in child[1]:  # 소스파일 단위로 for loop
        complexity = cal_complexity(child2)

        # for i in range(1, 26):  # 모든 메트릭 loop
        #     strTest = child2[i].text
        #     print(float(strTest))
        print(complexity)









# 우리가 정한 비율에 따라 각 function 점수 계산