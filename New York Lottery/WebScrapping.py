import urllib.request
from bs4 import BeautifulSoup
import PyPDF2

url = "http://nylottery.ny.gov/wps/portal/Home/Lottery/Home/Instant+Scratch-Off+Games/INSTANT+GAME+REPORTS/Top+Prizes+Report"
page = urllib.request.urlopen(url)
soup = BeautifulSoup(page, "html.parser")

#PDF Data link change weekly
data = soup.find('a',href =True, text= "Click here")
pdf = data['href']
pdf = "http://nylottery.ny.gov" + pdf
urllib.request.urlretrieve(pdf,"/Users/Eric/Desktop/test.pdf")

pdfReader = open('/Users/Eric/Desktop/test.pdf', 'rb')
myData = PyPDF2.PdfFileReader(pdfReader)
myData = myData.getPage(0)
print(myData.extractText())

f = open("/Users/Eric/Desktop/testing.txt", 'w')
f.write(myData.extractText())
f.close()