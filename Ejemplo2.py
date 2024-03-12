from scrapy.item import Item,Field
from scrapy.spiders import CrawlSpider,Spider,Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Mercado_Data(Item):

    articulo=Field()
    precio=Field()

class Extraer_data(CrawlSpider):

    name='automation'
    custom_settings = {

      'USER_AGENT':'Mozilla/5.0 (Macintosh; Intel Mac OS X 13_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36',
      'CLOSESPIDER_PAGECOUNT':10
    }
    #definir los dominios permitidos
    allowed_domain=['listado.mercadolibre.com.ec','articulo.mercadolibre.com.ec']

    #definir la pagina

    start_urls=['https://listado.mercadolibre.com.ec/animales-mascotas/perros/']
    download_delay=3

    #definir las reglas 

    rules = (

        #definir la regla Horizontal
       Rule( 
            LinkExtractor(
                allow=r'/_Desde_' 
            ), follow=True
        ),
        
    
        #definir la regla vertical

        Rule( 
            LinkExtractor(
                allow=r'/MEC-' 
            ), follow=True, callback='parse_items'),
    )

    def parse_items(self,response):

        item=ItemLoader(Mercado_Data(),response)
        item.add_xpath('precio','//span[@class="andes-money-amount__fraction"]/text()')
        yield item.load_item()



