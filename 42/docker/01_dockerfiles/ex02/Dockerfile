FROM ruby
LABEL maintainer="Lamine kaba laminekaba@outlook.com"
RUN apt-get update && apt-get -y upgrade \
	&& apt-get install -y nodejs build-essential
RUN gem install rails
RUN gem install bundler
RUN mkdir -p /opt/app

ONBUILD COPY ./app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD CMD gem install bundler
ONBUILD RUN bundle install