from scrapy.item import Item,Field
from scrapy.spiders import CrawlSpider,Spider
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Mercado(Item):

    precio=Field()
    apartamento=Field()

class Extraer_data(Spider):

    name='automation'
    custom_settings = {

      'USER_AGENT':'Mozilla/5.0 (Macintosh; Intel Mac OS X 13_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36'

    }

    allowed_domain=['encuentra24.com']
    start_urls=['https://www.encuentra24.com/costa-rica-es/bienes-raices-alquiler-apartamentos']
    download_delay=3

    def parse(self,response):

        sel=Selector(response)
        postings=sel.xpath('//div[@class="ann-ad-tile__content"]')

        for posting in postings:

            item=ItemLoader(Mercado(),posting)
            item.add_xpath('precio','.//div[@class="ann-ad-tile__price"]/text()')
            item.add_xpath('apartamento','.//a[@class="ann-ad-tile__title"]/text()')
            yield item.load_item()


   