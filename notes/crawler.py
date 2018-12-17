# from bs4 import BeautifulSoup
# import urllib.request

# sock = urllib.request.urlopen("https://leetcode.com/problems/tallest-billboard/description/") 
# webpage = sock.read()                            
# sock.close()                                        
# soup = BeautifulSoup(webpage, 'html.parser')
# print(soup)
# for anchor in soup.find_all('a'):
#     print(anchor.get('href', '/'))

# import urllib2
# from bs4 import BeautifulSoup
# from urlparse import urljoin


# def crawl(pages, depth=None):
#     indexed_url = [] # a list for the main and sub-HTML websites in the main website
#     for i in range(depth):
#         for page in pages:
#             if page not in indexed_url:
#                 indexed_url.append(page)
#                 try:
#                     c = urllib2.urlopen(page)
#                 except:
#                     print "Could not open %s" % page
#                     continue
#                 soup = BeautifulSoup(c.read())
#                 links = soup('a') #finding all the sub_links
#                 for link in links:
#                     if 'href' in dict(link.attrs):
#                         url = urljoin(page, link['href'])
#                         if url.find("'") != -1:
#                                 continue
#                         url = url.split('#')[0] 
#                         if url[0:4] == 'http':
#                                 indexed_url.append(url)
#         pages = indexed_url
#     return indexed_url


# pagelist=["https://104.31.64.244:443/problems/tallest-billboard/"]
# urls = crawl(pagelist, depth=2)
# print urls

from urllib.request import Request, urlopen

req = Request('https://leetcode.com/problems/tallest-billboard/', headers={'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:39.0) Gecko/20100101 Firefox/39.0'})
webpage = urlopen(req).read()
print(webpage)