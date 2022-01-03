"""
    crawler
"""

from __future__ import annotations

from bs4 import BeautifulSoup
import requests
import numpy as np
import re
import time

np.random.seed(int(time.time()))
pages_crawled = []

def crawler(url: str) -> None:
    page = requests.get(url)
    soup = BeautifulSoup(page.text, 'html.parser')

    links = soup.find_all('a', {'href': re.compile('^\/wiki\/((?!:).)*$')})
    link = links[np.random.randint(1, len(links) + 1)]

    if link not in pages_crawled:
        pages_crawled.append(link)
        new_link = f"https://en.wikipedia.org{link['href']}"
        try:
            with open('data.csv', 'a') as file:
                file.write(f'{soup.title.text}; {soup.h1.text}; {link["href"]}\n')
            crawler(new_link)
        except:
            pass

if __name__ == "__main__":

    url = 'https://en.wikipedia.org'
    crawler(url)
