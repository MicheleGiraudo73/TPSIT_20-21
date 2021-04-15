import logging
import threading
import time

def thread_function(name):
    logging.info("Thread %s: inizio", name)
    time.sleep(2) #mette in pausa il thread per 2 secondi
    logging.info("Thread %s fine", name)

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO,datefmt="%H:%M:%S")

    logging.info("Main      : creo il thread")
    x=threading.Thread(target=thread_function, args=(1,),daemon=True)
    logging.info("Main      : eseguo il thread")
    x.start() #avvio del thread x
    logging.info("Main      : attendere che il thread finisca")
    x.join() #attende che il thread x termini
    logging.info("Main      : fine")